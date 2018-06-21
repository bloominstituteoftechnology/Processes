// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// They both get their own copy of all the variables in the state they were in at time of fork
// Also the variable themselves are independent after that point.

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
        printf("Before changing X in child: x = %d\n", x);
        x = 50;
        printf("After changing X in child: x = %d\n", x);
    }
    else
    {
        printf("Before changing X in parent: x = %d\n", x);
        x = 25;
        printf("After changing X in parent: x = %d\n", x);
    }

    return 0;
}
