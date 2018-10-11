// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("Initial value of parent x: %d pid: %d\n", x, getpid());

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child: initial value %d pid: %d\n", x, getpid());
        x = 200;
        printf("Child: changed value %d pid: %d\n", x, getpid());
    }
    else
    {

        printf("Parent: initial value %d pid: %d\n", x, getpid());
        x = 300;
        printf("Parent: changed value %d pid: %d\n", x, getpid());
    }

    return 0;
}

// What value is the variable in the child process?
// The value is the same.

// What happens to the variable when both the child and parent change the value of x?
// The changed variables stay the same for the parent and child.
