// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("X is %i in the parent \n", x);

    int child_process = fork();
    // Begin execution of fork
    if (child_process < 0)
    {
        // Fork failed
        fprintf(stderr, "Fork Failed!");
        exit(1);
    } else if (child_process == 0)
    {
        // Fork succeeded
        x = 25;
        printf("X is %i in the child \n", x);
    }  else
    {
        printf("Back in the parent, X is: %i\n", x);
    }
    
    return 0;
}
