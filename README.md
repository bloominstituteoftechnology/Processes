# Processes

Now that we've talked a bit about how processes work at a high level, it's time to do 
some exercises regarding process creation. We'll be focusing on three of the most useful 
and versatile system call functions when it comes to process creation in UNIX systems. 
These are the `fork()`, `exec()`, and `wait()` system calls.

## Objective
To introduce and familiarize yourself with some basic system calls pertaining to process 
creation, to spawn some new processes, and to practice writing more C!

## `fork()`
The `fork()` system call is used by a parent process to create a new child process. Its 
actual implementation isn't as intuitive as it could be, though. When a parent process 
executes `fork()`, the new child process that is created is an almost exact copy of the 
calling process from the operating system's perspective. We say _almost_ an exact copy 
to delineate the fact that while the new child process has the same instruction set 
(i.e. code) as its parent process, the child process starts executing at the point right 
after `fork()` is called in the parent process. 

Let's look at a program that calls `fork()` to try to give an example of what this means:
```
// p1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    ------------------------------------------------ // child process starts executing here
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
```
Running this program, one of the possible outputs could be something like this:
```
prompt> ./p1
hello world (pid: 29146)
hello, parent here (pid: 29146) of child 29147
hello, child here (pid: 29147)
prompt>
```

So as we can see, the child process doesn't return the exact same output as its parent process, which 
is good, because otherwise spawning child processes wouldn't be nearly as useful. Notice that the child 
process has its own process identifier (PID); it also has its own address space, program counter, and 
execution context that are not the same as its parent's. 

More specifically, if we look at the `int rc = fork();` line, which both parent and chlid execute, they 
receive different results here. The parent process receives the PID of the child process it just spawned, 
while the child process receives 0 if the `fork()` call was successful. 

## `wait()`
So `fork()` allows us to spawn new child processes, but the thing with having multiple processes is that 
the order in which they execute is not deterministic, i.e., the parent may execute before the child or 
the child may execute before the parent; we can't say for certain. The `wait()` system call (along with 
the more complete `waitpid()` system call) allows us to get around this non-determinism if that is something 
that needs to be accounted for. Let's add a call to `waitpid()` in our previous example program to ensure that 
the child always runs before its parent:
```
// p2.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>    // `waitpid` needs to be included separately

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    ------------------------------------------------ // child process starts executing here
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
    } else {
        int wc = waitpid(rc, NULL);    // `waitpid` call added here
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
```
Here, the `waitpid()` function suspends the parent process until the child process pointed at by `rc` 
terminates. Thus, we ensure that the parent process only runs after the child process has finished its 
execution. 

## `exec()`
The last piece of the puzzle is the `exec()` system call, which is used in order to run a program that 
is different from the calling program (since `fork` only executes copies of the program that called it). 
Let's say we wanted to spin up a child process to execute a word count program. Here's how what a program 
that does that might look like:
```
// p3.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>    // this header file is needed in order to work with strings

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    ------------------------------------------------ // child process starts executing here
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
        char *myargs[3];    // allocate an array of chars to hold 3 bytes
        // `strdup` duplicates the given input string 
        myargs[0] = strdup("wc");    // pass the name of the program we want to run as the first array element 
        myargs[1] = strdup("p3.c");    // argument: the file to count
        myargs[2] = NULL;    // marks the end of the array
        execvp(myargs[0], myargs);    // runs the word count program, passing in the `myargs` array to the word count program as arguments
        printf("this should not be seen");
    } else {
        int wc = waitpid(rc, NULL);    // `waitpid` call added here
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
```
Here, we're doing the same thing as before, forking a new child process from a parent process. Then, inside that 
child process, we're calling `execvp()` with the arguments it needs to run the word count program. Note that `exec` 
does not spin up _another_ child process from the child process in which we called it. It transforms the process 
that called it into the new program that was passed to `exec`, in this case, `wc`, the word count process. That's 
why we still had to have the parent process `fork` a new child process. 

## What You'll be Doing for this Lab
This was your first introduction to making system calls to an operating system kernel. Obviously, there are many more 
system calls that we'll talk about in a future lesson, but for now we'll just practice with these three. Once you've 
cloned this repo, go into each directory, open up the exercise file, read the prompt, and write some C code! Compile 
your code with `gcc [NAME OF FILE].c -o [NAME OF EXECUTABLE]`.

## Further Reading
If you would like to read more on this topic, this chapter from _Operating Systems: Three Easy Pieces_ heavily 
informed this particular topic and material: [http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf](http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)
Additionally, it's always a good idea to read the man pages for any system calls you're trying to use:
 - The man page for `fork`: [https://linux.die.net/man/2/fork](https://linux.die.net/man/2/fork)
 - The man page for `wait` and `waitpid`: [https://linux.die.net/man/3/waitpid](https://linux.die.net/man/3/waitpid)
 - The man page for the `exec` family: [https://linux.die.net/man/3/exec](https://linux.die.net/man/3/exec)

