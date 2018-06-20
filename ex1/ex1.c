// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


/* value of the identical variable 'x' is different for both child and parent. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int rc = fork();
    if (rc < 0)
    {
        printf(stderr, "forkfailed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        int x = 100;
        printf("I am child, x = %d \n", x);
    }
    else
    {
        int x = 200;
        printf("I am parent, x = %d \n", x);
    }

    return 0;
}
