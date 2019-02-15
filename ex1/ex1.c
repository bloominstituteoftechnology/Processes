// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? A: 100.
// What happens to the variable when both the child and parent change the value of x?
// I updated the child by 1 and it printed 101
// And updated the parent by 2 and got 102.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int something = 100;
    int child = fork();

    if (child < 0)
    {
        fprintf(stderr, "fork failed.");
        exit(1);
    }
    else if (child == 0)
    {
        something += 1;
        printf("Child Something is: %d\n", something);
    }
    else
    {
        something += 2;
        printf("Parent Something is: %d\n", something);
    }

    return 0;
}
