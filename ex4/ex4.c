// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    int rc = fork(); // fork function: creates a new process by duplicating the calling process. Child process is created.
    if (rc < 0) // handling error during fork()
    {
        fprintf(stderr, "fork failed\n"); // error message; fprintf printing to standard error
        exit(1); //exit
    } 
    else if (rc == 0) // on successful forking, run this child process
    {
        char *ls_args[] = { "/bin/ls", "-1", NULL};
        printf("hello\n"); // child prints "hello"
        execvp(ls_args[0], ls_args);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0); //call wait() on parent to ensure that child process will always run first
        printf("goodbye\n"); // parent prints "goodbye"
    }
    
    return 0;
}
