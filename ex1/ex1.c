// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* fork() is used by a parent process to create a new child process. */

int main(int argc, char *argv[])
{
    int x;

    x = 13;
    printf("Hello, world! (pid: %d) \n", (int) getpid());
    printf("x = %d \n", x);

    int childProcess = fork();

    if (childProcess < 0){ // the fork failed
        fprintf(stderr, "FORK FAILED\n");
        printf("x = %d \n", x);
        exit(1);
    }
    else if (childProcess == 0){
        printf("I AM THE CHILD PROCESS (pid: %d) \n", (int) getpid());
        x = 21;
        printf("x = %d (childProcess) \n", x);
    }

    else {
        printf("I AM THE PARENT PROCESS (pid: %d) OF CHILD %d \n", (int) getpid(), childProcess);
        printf("x = %d (this is the parent) \n", x);
    } 

    return 0;
}
