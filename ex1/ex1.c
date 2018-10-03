// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // If there is a child, the rc of the child would be 0. X is still 100.
        x = 120;
        printf("child was here, x is: %d\n", x);
    }
    else
    { // still the parent process.
        x = 105;
        printf("parent process still, x is: %d\n", x);
    }
    printf("final x is: %d\n", x);
    // x is changed by the child if both parent and child change it, because child goes last.

    return 0;
}
