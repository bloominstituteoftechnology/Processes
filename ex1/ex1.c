// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("this is example 1 of a fork (pid: %d)\n", (int) getpid());
    int rc = fork();

    //child process starts executing
    if (rc < 0) {
        //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //child process satisfies this branch
        printf("HELLO!!, I'm the child (pid: %d) \n", (int) getpid());
    } else {
        printf("HEY, I'm the parent!! (pid: %d) of that child %d\n" , (int) getpid(), rc);
    }

    return 0;
}
