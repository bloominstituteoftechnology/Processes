// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 100;

    int rc = fork();

    if (rc == 0) // Child
    {
        printf("-------------\n");
        printf("Child Process\n");
        printf("-------------\n");
        printf("Value of x is %d\n", x);
        x = 200;
        printf("New Value of x is %d\n", x);
    }

    else if (rc > 0) // Parent
    {
        wait(NULL);
        printf("-------------\n");
        printf("Parent Process\n");
        printf("-------------\n");
        printf("Value of x is %d\n", x);
        x = 400;
        printf("New Value of x is %d\n", x);
    }

    else // Error
    {
        fprintf(stderr, "Error In Creating Process");
    }
}
