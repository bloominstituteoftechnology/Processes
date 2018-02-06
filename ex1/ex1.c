// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("This is child process\n");
        x = 75;
        printf("x = %d\n", x);
    }
    else
    {
        printf("This is parent process\n");
        x = 150;
        printf("x = %d\n", x);
    }

    printf("Current value of x = %d\n", x);

    return 0;
}
