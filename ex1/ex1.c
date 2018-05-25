// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //accessing variable
    int x = 100;
    //printing out that variable
    printf("x is: %d\n", x);

    int rc = fork();
    //child process begins
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x++;
        printf("hello, child here %d\n", x);
    }
    else
    {
        printf("hello,parent here (pid: %d) of child %d and the value of x: %d\n", (int)getpid(), rc, x);
        x--;
        printf("hello, parent here (pid: %d) and the value of x: %d\n", rc, x);
    }
    //print of final value after fork()
    printf("Value of x after the fork: %d\n", x);
    //new x value
    x = 75;
    return 0;
}
