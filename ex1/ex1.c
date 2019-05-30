// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int *x;
    x = malloc(sizeof(int));
    *x = 100;

    int rc = fork();

    if(rc == 0)
    {
        printf("Child x: %d\n", *x);
        printf("Child changing x\n");
        *x = 1;
        printf("New child x: %d\n", *x);
    }
    else
    {
        printf("Parent x: %d\n", *x);
        int wc = waitpid(rc, NULL, 0);
        printf("New parent x: %d\n", *x);
    }

    return 0;
}
