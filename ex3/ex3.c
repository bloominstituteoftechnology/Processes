// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // used to order processes by waiting 

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
        printf("hello\n"); // child prints "hello"
    }
    else
    {
        int wc = waitpid(rc, NULL, 0); //call wait() on parent to ensure that child process will always run first
        printf("goodbye\n"); // parent prints "goodbye"
    }
    
    return 0;
}
