// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 50;
    int child = fork();

    if (child == 0) // fork failed
    {
        printf("\n x = %d", x);
    }
    else
    {
        x = 60;
        printf("\n x = %d", x);
    }

    return 0;
}
