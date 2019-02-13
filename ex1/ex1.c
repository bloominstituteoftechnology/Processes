// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
    // The value is the same in the child process
// What happens to the variable when both the child and parent change the value of x?
    // Each retain their own copies and only edit their respective x

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    int rv = fork();

    if (rv < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    if (rv == 0)
    {
        printf("x is %d in the child process\n", x);
        x = 300;
        printf("x was changed to %d in the child process\n", x);
    }
    if (rv > 0)
    {
        printf("x is %d in the parent process\n", x);
        x = 500;
        printf("x was changed to %d in the parent process\n", x);
    }

    return 0;
}
