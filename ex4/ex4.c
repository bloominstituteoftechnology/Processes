// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?


//https://www.quora.com/Why-are-the-exec-family-of-functions-execl-execvp-etc-named-the-way-they-are
//execvpe() accepts arguments via vector, searches the user's path, 
//and accepts a new set of environment variables.
// L = arguments specified as a List.
// V = arguments specified as a Vector.
// (those first two are kind of a stretch)
// P = searches the Path.
// E = explicitly pass the Environment.


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here    
      printf("hello world (pid: %d)\n", (int) getpid());
      
    // ------------------------------------------------ child process starts executing here
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        execl("/bin/ls", "ls","-la", NULL);     // runs the ls program, passing in the `myargs` array as arguments
        printf("this should not be seen");
    } else {
        int wc = wait( NULL);    // wait for the child process exec to end first
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
