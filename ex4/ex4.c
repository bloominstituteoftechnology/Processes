// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>  // installing the necessary header files
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>   // for calling the wait() function

int main(void)
{
    // Your code here
    int rc = fork();    // fork function: creates a new process by duplicating the calling process. Child process is created.

    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "fork failed\n");   // error message; fprintf printing to standard error
        exit(1);    // exit 
    } else if (rc == 0) {   // on successful forking, run this child process 
        printf("Child process here\n"); // print this for child
        char *args[] = {"ls", "-l", NULL}; // initialize args array, ls program/function, -l flag, and null terminator; transform child into ls
        execvp("ls", args); // call exec() system call taking in ls and the args array 
        printf("This should not be seen\n");    // this is seen only if there's an error or unsuccessful
    } else {
        int wt = waitpid(rc, NULL, 0);  // call wait() function on parent
        printf("Parent process here\n");    // print this for parent
    }

    return 0;
}