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
    printf("x value is: %d\n", x);
    int child = fork();

    if (child < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        printf("This is the child. Initial x value is %d\n", x);
        printf("Changing x value...\n");
        x = 20;
        printf("x value is now: %d\n", x);
    }
    else
    {
        printf("This is the parent. Initial x value is %d\n", x);
        printf("Changing x value...\n");
        x = 99;
        printf("x value is now: %d\n", x);
    }

    return 0;
}
