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
        fprintf(stderr, "fork() failed\n");
    }
    else if (rc == 0)
    {
        printf("Child int x before= %d\n", x);
        x = 1000;
        printf("Child int x after= %d\n", x);
    }
    else
    {
        printf("Parent int x before= %d\n", x);
        x = 10;
        printf("Parent int x after= %d\n", x);
    }

    /*
        1) The value of var x is the same in both child and parent.

           Parent int x = 100
           Child int x = 100

        2) Changing the value in either parent or child does not affect
           other process' x value.

           Parent int x before= 100
           Parent int x after= 10
           Child int x before= 100
           Child int x after= 1000

           This is due to the fact that calling fork() copies the original code
           (as opposed to "refs" like in arrays and objects in JS).
    */

    return 0;
}
