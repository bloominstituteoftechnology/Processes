// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 5;
    printf("%d: the value of x is %d\n", getpid(), x);

    fork();

    if (x == 5)
    {
        x = 3;
        printf("%d [parent: %d] The value of x is %d\n", getpid(), getppid(), x);
    }

    return 0;
}
