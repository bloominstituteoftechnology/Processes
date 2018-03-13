// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("value of x in main is: %d\n", x);

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x++;
        printf("hello, child here (pid: %d), my value of x is: %d\n", (int)getpid(), x);
    }
    else
    {
        printf("hello, parent here (pid: %d) of child %d and my value of x is: %d\n", (int)getpid(), rc, x);
        x--;
        printf("hello, parent again (pid: %d) and my value of x is: %d\n", rc, x);
    }

    printf("Value of x after the fork: %d\n", x);
    x = 99;

    return 0;
}
