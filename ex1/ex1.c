// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 10;

    int pid = fork();

    if (pid == 0)
    {
        printf("Child: x is '%d'\n", x);
        x++;
        printf("Child: x after incrementing is '%d'\n", x);
    }
    else
    {
        printf("Parent: x is '%d'\n", x);
        x = 20;
        printf("Parent: x after changing value to 20 is '%d'\n", x);
    }

    return 0;
}
