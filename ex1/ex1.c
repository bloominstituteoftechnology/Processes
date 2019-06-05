// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here

    pid_t pid = fork();

    if (pid == 0)
    {
        int x = 200;
        printf("\n This is the child, x = %d\n", x);
        exit(1);
    }
    else
    {
        int x = 100;
        printf("\n This is the parent, x = %d\n", x);
    }

    return 0;
}
