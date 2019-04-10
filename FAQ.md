# FAQ

## Contents

### Common Errors

* [When writing to the same file from two processes, the writes both seem to occur just fine, even though the problem suggests it won't work. What's going on?](#q2300)
* [Does a return value of `-1` usually indicate an error?](#q1000)

### Operating Systems

* [What is a syscall/system call?](#q100)
* [What's a privileged vs non-privileged operation?](#q200)
* [How does I/O with the keyboard and other peripherals work?](#q400)
* [Where does the OS keep the process list? How does it relate to the stack and heap?](#q600)
* [Where is the process control block stored?](#q1500)
* [Does a return value of `-1` usually indicate an error?](#q1000)
* [If old operating systems like MS-DOS didn't offer a privileged mode or memory protection, how did they offer features dependent on those to their users?](#q1200)
* [Is there a way to control how the OS schedules processes, to give them higher priority?](#q1600)
* [Is the kernel "close to the metal"?](#q1700)
* [How does the OS assign a particular memory space to a particular process?](#q1900)
* [What are `stdin`, `stdout`, and `stderr`?](#q2900)
* [How do I know which header files to `#include` for any particular function?](#q3000)

### Processes

* [How does the scheduler decide which process to run next?](#q500)
* [Where does the OS keep the process list? How does it relate to the stack and heap?](#q600)
* [If processes are isolated from one another, what's the point of using `pipe()`?](#q700)
* [Where is the process control block stored?](#q1500)
* [Is there a way to control how the OS schedules processes, to give them higher priority?](#q1600)
* [How does a process dynamically resize how much memory is has at its disposal?](#q1800)
* [How does the OS assign a particular memory space to a particular process?](#q1900)

### Syscalls

* [What is a syscall/system call?](#q100)
* [Does compiled code make system calls under the hood?](#q300)
* [How do I know which header files to `#include` for any particular function?](#q3000)

### Pipes

* [If processes are isolated from one another, what's the point of using `pipe()`?](#q700)
* [What are some use cases for pipes?](#q1300)
* [How many bytes can a pipe hold?](#q2500)
* [What happens when you try to read from an empty pipe? Or when you try to write to a full pipe?](#q2600)

### Fork/Wait, Zombies

* [When you `fork()`, is the parent's PID always greater than zero?](#q800)
* [Should I use `wait()` or `waitpid()`?](#q900)
* [Is the `fork()` syscall where the word "fork" on GitHub came from?](#q1100)
* [Isn't it expensive to copy all the data on a `fork()`?](#q1400)
* [When doing a `fork()`, you only need the conditional if you want the parent and child to do different things?](#q2000)
* [How could you create a grandchild process?](#q2100)
* [How do I create sibling processes?](#q2200)
* [Can `fork()` return less than `0`?](#q2400)
* [Can a child process `wait()` on a parent?](#q2700)
* [How can a parent get the exit status from a child process?](#q2800)
* [Is a zombie like when you have to end a task with the Task Manager?](#q3100)
* [What happens if a parent dies before it `wait()`s on its children? Do they become zombies forever?](#q3200)
* [Is there any other way to create processes other than using `fork()`?](#q3300)
* [How does `fork()` work under the hood?](#q3400)

## Questions

<a name="q100"></a>
### What is a syscall/system call?

From a C programming perspective, you can think of a syscall as a function that
you call to get the OS to do something for you. It looks just like a regular
function, but the behavior is different.

This is not a syscall:

```c
double x = sqrt(2);
```

You don't need any special access to hardware to compute a square root, so that
just happens in _user space_ without involving the OS.

This _is_ a syscall:

```c
int fd = open("file.txt", O_CREAT|O_WRONLY);
```

Opening a file is something a regular user can't do (since they don't have
direct access to the hard disk). The `open()` syscall asks the OS to open the
file on the user's behalf. And the OS can agree or disagree to do that depending
on the user's authority level.

------------------------------------------------------------------------

<a name="q200"></a>
### What's a privileged vs non-privileged operation?

Privileged operations need additional access to hardware or data that the user
is not normally allowed to access.

There are privileged instructions that a CPU won't execute unless in the proper
"supervisor" mode (sometimes called _ring-0_, or _system mode_ or _privileged
mode_).

An example might be accessing a file on a hard disk. A user cannot do this by
talking directly to the hardware. The user must request the OS do it on their
behalf using a syscall.

A non-privileged operation might be something like computing a square root. This
doesn't require any additional access to hardware, and the user program can do
this without asking the OS for anything.

Going between these modes is called a _context switch_. The state of the running
program is saved (so it can be restarted later), and then the OS kernel decides
what to do next. Sometimes it's executing a syscall on a process's behalf. Other
times it's scheduling an entirely different process to run.

```
        User mode           |          Privileged mode
        ---------           |          ---------------
compute square root         |
estimate pi                 |
open a file         <-------+------->    open syscall
compute pi/2                |
write to file       <-------+------->    write syscall
add 3 + 7                   |
```

------------------------------------------------------------------------

<a name="q300"></a>
### Does compiled code make system calls under the hood?

Yes.

Here's an example of a function that runs partly in user space, but then makes a
syscall to complete the work:

```c
printf("%d\n", x);
```

The `printf()` library function does all the hard work of converting `x` into a
string that can be printed, but actually outputting to the screen is a
privileged operation.

So under the hood, `printf()` calls the `write()` syscall to actually perform
the final output.

------------------------------------------------------------------------

<a name="q400"></a>
### How does I/O with the keyboard and other peripherals work?

From a programming standpoint, virtually all I/O in a Unix-like system takes
place through the `read()` and `write()` syscalls. These send and receive arrays
of bytes to and from open files.

One of the files that's open by default is called _standard input_. This is
normally attached to the keyboard.

```c
char buf[10];

read(0, buf, 10); // Read 10 bytes from stdin, file descriptor 0
```

Another is _standard output_, normally attached to the screen.

```c
write(1, "Hello, world!\n", 14); // print to stdout, file descriptor 1
```

In Unix, the `/dev` directory contains a number of special _device files_ that
correspond to physical devices on the system. The usual method of accessing them
involves `open()`ing the file, then interacting with it with `read()`,
`write()`, `ioctl()`, and `fcntl()`. Of course, your user needs permission to
open the device file to make this work.

------------------------------------------------------------------------

<a name="q500"></a>
### How does the scheduler decide which process to run next?

The _scheduler_ is a component inside the OS that decides which process needs to
run next. Your CPU might only have 4 or 8 cores, so it can actually only do that
many things at once.

But a Unix system might have 200 processes running at the same time, and those
200 processes have to be juggled across the few cores a CPU has.

Imagine a room with 200 reporters and they all want to ask the President a
question. But only one can ask a question at a time. The President calls on one
of the reporters to ask a question, answers, then calls on the next one. How
does the President decide which reporter to call on next? That is the job of the
scheduler.

The scheduler looks at all 200 processes and decides which one to run next.

Now, _how_ it decides is up to whatever scheduler algorithm is implemented.
Imagine you were the President selecting which reporter to call on next. There
are a number of algorithms you could use. (Choose randomly, go in order, choose
the ones you personally like the most, etc.)

But a good scheduling algorithm should give CPU time to processes that the user
expects to see a snappy response from, and less time to "background" processes
that can be delayed a bit.

The [multilevel feedback
queue](https://en.wikipedia.org/wiki/Multilevel_feedback_queue) is a popular
scheduling algorithm, but there are [many
others](https://en.wikipedia.org/wiki/Scheduling_(computing)#Scheduling_disciplines).

------------------------------------------------------------------------

<a name="q600"></a>
### Where does the OS keep the process list? How does it relate to the stack and heap?

Since the process list exists _outside_ any processes that are running, it
exists neither in a processes's stack nor in its heap.

From an individual process's perspective on a modern OS, the process thinks it
has all the memory on the entire system to itself. It's an illusion, though,
brought about by the magic of [virtual
memory](https://en.wikipedia.org/wiki/Virtual_memory). This is where the
individual processes's stacks and heaps are kept.

So if the process thinks it has all the RAM, where are the process list and
other OS internals kept?

The OS kernel has its own bit of dedicated memory allocated to it, and all the
internal data (process list, etc.) are kept there.

Regular user processes have zero access to this data, except via syscalls or
some other mechanism that the OS explicitly allows.

------------------------------------------------------------------------

<a name="q700"></a>
### If processes are isolated from one another, what's the point of using `pipe()`?

If you set up the `pipe()` _before_ the `fork()`, then both parent and child
have access to the pipe's file descriptors and they remain connected.

They can then use the pipe to send messages back and forth.

(Pipes are part of a collection of Unix calls known collectively as
_interprocess communication_.)

If you mistakenly call `pipe()` _after_ `fork()`, then the parent and child will
have their on separate, disconnected pipes, and there'd be no point in it.

------------------------------------------------------------------------

<a name="q800"></a>
### When you `fork()`, is the parent's PID always greater than zero?

Yes.

But technically, _all_ PIDs are greater than zero.

`fork()` returns `0` to the child process, but the child process's PID is
some other positive number.

The `0` returned by `fork()` is a _sentinel value_ that allows the program to
determine which process is the parent and which is the child.

Any process can call `getpid()` to find out its PID. It can also call
`getppid()` to get the parent process's PID.

(There is no `getchildpid()` call, though, since a parent might have multiple
child processes. The only way for a parent to know the PID of its children is to
remember them from the return value from `fork()`.)

------------------------------------------------------------------------

<a name="q900"></a>
### Should I use `wait()` or `waitpid()`?

`waitpid()` is just like wait, except it gives you more options. With
`waitpid()`, you can wait for specific processes to exit, or for processes in a
process group. You can also specify if you want the `waitpid()` call to block or
not if there are no zombie children waiting to be reaped.

Example where the calls to `wait()` are identical to `waitpid()`:

```c
wait(NULL);
waitpid(-1, NULL, 0);
```

```c
int status;

wait(&status); // Get exit status from child zombie
waitpid(-1, &status, 0);
```

And here's an example of using `waitpid()` to wait for all children that might
have died, but then continuing to run if there are no zombies remaining.

```c
printf("Reaping zombies...\n");

// WNOHANG causes waitpid() to return 0 if
// there are no zombies remaining:

while (waitpid(-1, NULL, WNOHANG) > 0);

printf("Done reaping zombies.n");
```

Normally `wait()` and `waitpid()` will _block_ (sleep) until they have something
to do. But if you specify `WNOHANG` to `waitpid()`, it will return `0`
immediately if there are no child zombies to reap.

------------------------------------------------------------------------

<a name="q1000"></a>
### Does a return value of `-1` usually indicate an error?

It's common in general, and really common with syscalls.

The usual pattern to:

1. Make a syscall.
2. See if the return value is `-1`.
3. Use `perror()` to print an error, or check `errno` to decide what to do.

Example where we try to open a non-existent file for reading:

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("nosuchfile.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
}
```

Output from the above:

```shell
$ ./foo
Error opening file: No such file or directory
```

You can also check the exact value of the `errno` global variable (from
`<errno.h>`) to see what specific error occurred and act on it.

In this example, we try to write to (and maybe create) the `/etc/passwd` file.
Normal users don't have permission to do this. (**NOTE**: don't run this as
`root`!)

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    int fd = open("/etc/passwd", O_CREAT|O_WRONLY);

    if (fd == -1) {
        switch errno {
            case EACCES:
                printf("You don't have permission to open this file.\n");
                break;
            case ENOENT:
                printf("No such file.\n");
                break;
            case ENOSPC:
                printf("Disk full.\n");
                break;
            default:
                perror("Error opening file");
                break;
        }
        exit(1);
    }
}
```

When a normal user runs this, they see:

```shell
$ ./foo
You don't have permission to open this file.
```

The values you can check for with `errno` are listed in the man page for the
syscall in question.

------------------------------------------------------------------------

<a name="q1100"></a>
### Is the `fork()` syscall where the word "fork" on GitHub came from?

Probably not.

GitHub needed a name for when you branched off someone else's repo.
Unfortunately for them, _branch_ already means something else to git. Seems
likely they just used fork as a similar word.

------------------------------------------------------------------------

<a name="q1200"></a>
### If old operating systems like MS-DOS didn't offer a privileged mode or memory protection, how did they offer features dependent on those to their users?

In a nutshell, they didn't.

You could write a program and run it in MS-DOS that could directly access
hardware, modify or overwrite the OS, or do all manner of bad things.

But those systems tended to be single-user (a family would just share with no
privacy) and it wasn't that big of a deal. Crash the system? You'd just reboot.

Rebooting happened a lot.

------------------------------------------------------------------------

<a name="q1300"></a>
### What are some use cases for pipes?

When you `fork()` a new process, it gets a copy of all the data. None of it is
shared. But there might be times you want to communicate between a child and
parent process.

If you set up a pipe ahead of the `fork()`, copies of that pipe's descriptors
get made for the child. But here's the magic: those descriptors still refer to
the underlying shared pipe as they do in the parent. They're still connected.

This means you can pass data across the pipe from one to the other.

Another use case is used by the shell when you run a command like this:

```shell
ls -l | wc -l
```

That pipes the output from the `ls` program to the input of `wc` (a word
counting program). The `pipe()` syscall is used to set up that communication
path between the two completely separate processes. (It also makes use of the
syscall `dup2()` to actually hook up the input and output to the pipe.)

```c
/**
 * Pipe example
 *
 * Runs the command: ls -la / | wc
 *
 * Try running the above command on the command line to see if the
 * output matches.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    int fd[2];

    // Make the pipe for communication
    pipe(fd);

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process

        // Hook up standard input to the "read" end of the pipe
        dup2(fd[0], 0);

        // Close the "write" end of the pipe for the child.
        // Parent still has it open; child doesn't need it.
        close(fd[1]);

        // Run "wc"
        execlp("wc", "wc", NULL);

        // We only get here if exec() fails
        perror("exec wc");
        exit(1);
    } else {
        // Parent process

        // Hook up standard output to the "write" end of the pipe
        dup2(fd[1], 1);

        // Close the "read" end of the pipe for the parent.
        // Child still has it open; parent doesn't need it.
        close(fd[0]);

        // Run "ls -la /"
        execlp("ls", "ls", "-la", "/", NULL);

        // We only get here if exec() fails
        perror("exec ls");
        exit(1);
    }

    return 0;
}
```

------------------------------------------------------------------------

<a name="q1400"></a>
### Isn't it expensive to copy all the data on a `fork()`?

Seems like it would cost a lot to give the child a complete copy of all the
process data.

But modern operating systems implement something called [_copy on
write_](https://en.wikipedia.org/wiki/Copy-on-write) so that the data isn't
copied until the child process wants to modify it. _Then_ a copy is made.

If you're 100% certain that you're just going to call `exec()` right after
`fork()`, then there's no reason to copy anything at all. There's a historic
syscall called `vfork()` that you could use if you were _only_ going call
`exec()` after the fork.  On modern systems, `vfork()` might be marginally
faster for that use case, or it might work exactly the same way as `fork()`.

------------------------------------------------------------------------

<a name="q1500"></a>
### Where is the process control block stored?

That's somewhere deep in kernel memory. It's not something you can directly
access as a user. You have to use syscalls to ask the OS for information about
the process.

------------------------------------------------------------------------

<a name="q1600"></a>
### Is there a way to control how the OS schedules processes, to give them higher priority?

As a normal user, you can request the OS give your program _lower_ priority in
the scheduler with the `nice()` syscall.

```c
nice(10); // Be pretty nice to other processes on the system (lower priority)
```

```c
nice(20); // Be as nice as possible (lowest priority)
```

The default priority level is `0`.

If you're superuser (running as `root`), you can assign _negative nice_ levels
(AKA _mean_ levels).

```c
nice(-20); // Be as mean as possible to other processes (highest priority)
```

Particular systems might have other methods of manipulating scheduling, but
they're all going to involve making a request to the OS.

------------------------------------------------------------------------

<a name="q1700"></a>
### Is the kernel "close to the metal"?

Definitely. It's the arbiter of all access to all the hardware on the system.

Not only that, but the boot-up sequence of an OS is almost always written in
assembly language, as close to the metal as programmers typically go. (Although
as much of the OS as possible is written in a higher-level language because it's
so much easier.)

The expression _close to the metal_ is also used to refer to programming
languages. An example list with closer to the metal at the top would be,
roughly:

* Machine code
* Assembly language
* C
* C++, Rust
* Go, Swift
* JavaScript, Python, Perl
* TypeScript

------------------------------------------------------------------------

<a name="q1800"></a>
### How does a process dynamically resize how much memory is has at its disposal?

It asks the OS for more.

On Unix-like systems, this is done with the `brk()` or `sbrk()` syscall.

Normally, C developers don't call this. They call `malloc()` to get more memory,
and `malloc()` calls `brk()` if it needs to get more for this process from the
OS.

------------------------------------------------------------------------

<a name="q1900"></a>
### How does the OS assign a particular memory space to a particular process?

This is out of scope for the class, but is all about the crazy world of [virtual
memory](https://en.wikipedia.org/wiki/Virtual_memory). Read up on that if you
want all the gritty details.

------------------------------------------------------------------------

<a name="q2000"></a>
### When doing a `fork()`, you only need the conditional if you want the parent and child to do different things?

Yes.

And it is probably 99.999% of the time you'll want the parent and child to do
different things.

------------------------------------------------------------------------

<a name="q2100"></a>
### How could you create a grandchild process?

Call `fork()` from the would-be grandparent, then call `fork()` again from its
child.

------------------------------------------------------------------------

<a name="q2200"></a>
### How do I create sibling processes?

Just call `fork()` multiple times from the parent.

------------------------------------------------------------------------

<a name="q2300"></a>
### When writing to the same file from two processes, the writes both seem to occur just fine, even though the problem suggests it won't work. What's going on?

It turns out that with such small writes, and especially on Windows, the writes
come out sequentially even though they're running at the "same" time.

The demo would work better if the writes were much larger, like 512 K per write.

But the point is that any time you have multiple processes accessing _any_
shared resource, there needs to be some kind of locking in place to prevent the
processes from stepping on each other's toes.

With files, that would be some kind of file locking.

Other shared resources that you might already be familiar with, such as
databases, do their own locking so you don't have to worry about it. But on
Unix, files aren't locked automatically.

See also: [`lockf()`](http://man7.org/linux/man-pages/man3/lockf.3.html).

------------------------------------------------------------------------

<a name="q2400"></a>
### Can `fork()` return less than `0`?

Yes, in the case of an error.

It's best practice to check to see if it returned `-1` and react appropriately.

Most Unix syscalls return `-1` in the case of an error, and set the global
variable `errno` to reflect the error that occurred.

------------------------------------------------------------------------

<a name="q2500"></a>
### How many bytes can a pipe hold?

The size of the pipe is fixed by the operating system, and varies from system to
system. It's likely at least 12 KB, but is probably more.

Here's a small program that will sleep once the pipe fills up, telling you how
many bytes fit in the pipe:

```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int count = 0;
    int fd[2];

    pipe(fd);

    while (1) {
        write(fd[1], "A", 1);
        printf("byte count: %d\n", ++count);
    }

    return 0;
}
```

On a Mac, this reported that the pipe held 64 KB (65536 bytes).

------------------------------------------------------------------------

<a name="q2600"></a>
### What happens when you try to read from an empty pipe? Or when you try to write to a full pipe?

The OS will put the process that called `read()` or `write()` to sleep if
there's nothing to read or the pipe is full.

The process will be woken up as soon as it's possible for it to do more work.

------------------------------------------------------------------------

<a name="q2700"></a>
### Can a child process `wait()` on a parent?

No.

Parents can only wait on their children, not the other way around.

------------------------------------------------------------------------

<a name="q2800"></a>
### How can a parent get the exit status from a child process?

The `wait()` syscall accepts a pointer to an `int` that it fills with exit
status information.

Here's a rough example. Note that this example omits error checking for brevity.
There are a number of reasons a program can exit (it might exit normally, or be
killed, or a number of other things), and you should check with macros such as
`WIFEXITED()` before assuming there's an exit status to be reported.

See the [`wait()` man page](http://man7.org/linux/man-pages/man2/waitpid.2.html)
for more.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    if (fork() == 0) {
        printf("Child: exiting with status 3\n");
        exit(3);

    } else {
        int status;

        wait(&status);

        printf("Parent: child exited with status %d\n", WEXITSTATUS(status));
    }
}
```

------------------------------------------------------------------------

<a name="q2900"></a>
### What are `stdin`, `stdout`, and `stderr`?

These are the three files that are automatically opened for a process when it is first created.

|Stream           | Short Name | File Descriptor | Symbolic File Descriptor |  Device  |
|-----------------|:----------:|:---------------:|:------------------------:|:--------:|
| Standard Input  |  `stdin`   |       `0`       |      `STDIN_FILENO`      | Keyboard |
| Standard Output |  `stdout`  |       `1`       |      `STDOUT_FILENO`     |  Screen  |
| Standard Error  |  `stderr`  |       `2`       |      `STDERR_FILENO`     |  Screen  |

`stderr` is typically used specifically for error messages, even though it goes
to the same place as `stdout`. (The idea is that you can redirect all normal
output to one place, and all error output to another place. Or suppress normal
output while allowing error output.)

------------------------------------------------------------------------

<a name="q3000"></a>
### How do I know which header files to `#include` for any particular function?

Check the man page for the function in question. It'll show it in the _Synopsis_
section.

Example for `printf()`:

> **SYNOPSIS**
> ```c
>    #include <stdio.h>
> ```
> ```c
>     int
>     printf(const char * restrict format, ...);
> ```

Note that if you type `man` on the command line for a particular function, you
might a manual page for another command that isn't the C function. In that case,
you have to specify the proper _section_ of the manual for the function.

Try section 3 for library functions, and section 2 for syscalls.

Example looking for `printf()` in section 3:

```shell
man 3 printf
```

And section 2 for the `mkdir()` syscall:

```shell
man 2 mkdir
```

------------------------------------------------------------------------

<a name="q3100"></a>
### Is a zombie like when you have to end a task with the Task Manager?

Not quite.

Normally, when you kill a process explicitly (with the task manager or the Unix
kill command), that process is still alive, but is misbehaving in some way.
(It's frozen, or eating CPU resources or something.)

Zombie processes, by comparison, are no longer alive. They've already exited.
They're no longer running. In Unix, you can't kill them because they're already
dead.

The only way to get rid of the zombie is:

1. Have the parent `wait()` for it.
2. If the parent is dead, then the zombie child is adopted by init (PID 1), and
   init calls `wait()` for it.

------------------------------------------------------------------------

<a name="q3200"></a>
### What happens if a parent dies before it `wait()`s on its children? Do they become zombies forever?

Fortunately, no.

It's true that a child process becomes a zombie until its parent waits for it.

But if their parent dies, how can that parent wait on it?

There's one more rule of processes in Unix: if a process's parent dies, that
process is _adopted_ by the init process (PID 1). This means that a process will
have a parent at all times, even if its original parent died.

And init is really good at reaping zombies. It frequently calls `wait()` to make
sure all its zombie children are taken care of.

One path:

1. Parent `fork()`s a child.
2. Parent dies, becomes a zombie
3. Child is adopted by init.
4. Parent zombie is reaped by its parent calling `wait()`.
5. Child dies, becomes a zombie.
6. Child zombie is reaped by init calling `wait()`.

Another possible path:

1. Parent `fork()`s a child.
2. Child dies, becomes a zombie.
3. Parent dies, becomes a zombie
4. Child zombie is adopted by init.
5. Parent zombie is reaped by its parent calling `wait()`.
6. Child zombie is reaped by init calling `wait()`.

In any case, all zombies are reaped properly.

------------------------------------------------------------------------

<a name="q3300"></a>
### Is there any other way to create processes other than using `fork()`?

No. That's all you got.

And coupled with `exec()`, it's really all you need.

------------------------------------------------------------------------

<a name="q3400"></a>
### How does `fork()` work under the hood?

It's not required to know this to be an effective Unix systems developer, but it
is useful information for the curious.

This is adapted from Maurice J. Bach's fantastic book, [_The Design of the UNIX
Operating
System_](https://books.google.com/books/about/The_Design_of_the_UNIX_Operating_System.html?id=NrBQAAAAMAAJ).

Note that this is _not_ how to use the `fork()` syscall; this is how the
`fork()` syscall is implemented inside the OS. If you were writing your own
Unix-like OS, you'd use an algorithm like this one.

```pseudocode
// This is pseudocode!

// algorithm: fork
//
// input:  none
//
// output: to parent process, child PID number
//         to child process, 0

pid_t fork(void)
{
    // Do some initial checks to make sure the user can call fork()
    // at this time. If any of these fail, fork() will return -1.

    check for available kernel resources;
    check that the user not running too many processes;

    // Create a new process table entry for the child:

    get free process table slot for child;
    get unique PID number for child;
    mark child state as "being created";
    copy data from parent process table slot to new child slot;

    // Bookkeeping on resources referenced by the child:

    increment counts on current directory inode;
    increment counts on changed root (if applicable);
    increment open file counts in file table;

    // This is what gives the child a copy of all the parent's variables and code:

    make a copy of parent context (u area, text, data, stack) in memory;

    // We need to let the child know that it's supposed to begin its life here
    // in kernel mode in the middle of this fork() call:

    push dummy system level context layer onto child system level context;

    // The dummy context contains data allowing the child process to
    // recognize itself, and start running from the following "if" statement
    // when scheduled:

    if (executing process is parent process) {
        // We're the parent

        set child state to "ready to run";

        // The return value of fork() is the new child's PID if we're
        // the parent:

        return childPID; // from kernel mode to user mode

    } else {
        // We're the child

        initialize u area timing fields;

        // The return value of fork() is 0 if we're the child:

        return 0; // from kernel mode to user mode
    }
}
```

------------------------------------------------------------------------