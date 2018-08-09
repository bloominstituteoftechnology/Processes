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
    int rc = fork();  // creates a new child process that runs its code starting under this line

    if (rc < 0)
    {
        fprintf(stderr, "For failed!\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child variable `x` is equal to: %d\n", x);

        x = 50;  // child changes the value of `x`

        printf("Child variable `x` is equal to: %d\n", x);
    }
    else
    {
        printf("Parent variable `x` is equal to: %d\n", x);

        x = 150;  // parent changes the value of `x`

        printf("Parent variable `x` is equal to: %d\n", x);
    }
    
    return 0;
}
