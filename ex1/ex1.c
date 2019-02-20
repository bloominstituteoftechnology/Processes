// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// 1. What value is the variable in the child process?
// The value is also the same. It looks like the x variable is in a global scope.

// 2.What happens to the variable when both the child and parent change the value of x?
// The x variable changes due to the scope of being inside the conditional statements.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("x value before calling fork: %d \n", x);

    int rc = fork();

    // child process starts execution here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        x = 200;
        printf("hello, child here (pid: %d) \n", (int)getpid());
        printf("x value in child when changed: %d \n", x);
    }
    else
    {
        x = 300;
        printf("hello, parent here (pid: %d) of child %d \n", (int)getpid(), rc);
        printf("x value in parent when changed: %d \n", x);
    }

    return 0;
}
