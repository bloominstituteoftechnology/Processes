// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("What is the value of x? %d\n", x);
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x = 50;
        printf("This is the child (pid: %d) process - the value of x is %d\n", (int) getpid(), x);
    }
    else
    {
        x = 25;
        printf("This is the parent (pid: %d) process of %d - the value of x is %d\n", (int) getpid(), rc, x);
    }
    return 0;
}
