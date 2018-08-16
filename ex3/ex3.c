// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>  // installing the necessary header files
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>   // for calling the wait system call

int main(void)
{
    // Your code here
    int rc = fork();    // fork function: creates a new process by duplicating the calling process. Child process is created.

    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "fork failed\n");   // error message; fprintf printing to standard error
        exit(1);    // exit 
    } else if (rc == 0) {   // on successful forking, run this child process 
        printf("Hello!\n"); // child prints Hello!
    } else {
        int wc = waitpid(rc, NULL, 0);  // call wait() function on parent to ensure that child process will always run first
        printf("Goodbye!\n");   // parent prints Goodbye!
    }
    
    return 0;
}