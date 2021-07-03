// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int something = 100;
    int child = fork();
    if(child == 0) {
        something += 1;
        printf("Child something is: %d\n", something);
    } else {
        something += 2;
        printf("Parent something is: %d\n", something);
    }
    return 0;
}
