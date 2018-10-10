// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf(" Value of x is %d\n ", x);

    int newP = fork();
    printf("parent is calling for a child value %d\n", newP);
    // Your code here
    if (newP == 0)
    {
        printf(" if pid == 0 , value of x is %d\n", x);
        printf(" if pid == 0 , newP is %d\n", newP);
        x = 94;
        printf("after value is = 94, x is %d\n", x);
        printf("after value is = 94, newP is %d\n", newP);
    }
    else
    {
        printf(" else x is %d\n", x);
        printf(" else newP is %d\n", newP);
        x = 43;
        printf(" after value is = 43, x is %d\n", x);
        printf(" after value is = 43, newP is %d\n", newP);
    }
    return 0;
}
