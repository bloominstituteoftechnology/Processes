// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


#include <stdio.h>  //installing the necessary libraries
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid()); // run hello world and retrieve pid or process id. This is the parent process and the parent pid.
    int rc = fork();    // fork function: creates a new process by duplicating the calling process. Child process is created.
    
    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "fork failed\n");   // error message
        exit(1);    // exit
    } else if (rc == 0) {   // on successful forking, this is the child process which is the duplicate of the parent process
        printf("hello, child here(pid: %d) \n", (int)   // running the exact same process as the parent; child's pid or process id should not match any existing pid
        getpid());
    } else {    // on successful forking of child process, the pid of the child is retrurned in the parent
        printf("hello, parent here (pid: %d) of child %d\n",    // the child's parent pid is the same as the parent's pid
        (int) getpid(), rc);
    }
    return 0;
}