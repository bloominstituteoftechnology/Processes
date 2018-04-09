// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Answer: It increments only its own copy and does not affect the other process' copy

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork failed, exiting.\n");
        exit(1);
    } else if (rc == 0) {
        printf("Fork succeeded; incremented child x value is %d\n", ++x);
    } else {
        printf("Fork succeeded; incremented parent x value is %d\n", ++x);
    }

    return 0;
}
