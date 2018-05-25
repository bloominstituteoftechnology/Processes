// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? iInit
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 25;
    printf("Before: %d\n", x);
    int rc = fork();
    // new process begins
    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x++;
        printf("Child: %d\n", x);
    }
    else
    {
        x--;
        printf("Parent: %d\n", x);
    }

    return 0;
}
