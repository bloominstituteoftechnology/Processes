// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;

    int y = fork();

    if (y < 0) {
        fprintf("fork failed\n", x);
        exit(1);
    } else if (y == 0) {
        printf("from child and x is: %d\n", ++x);
    } else {
        printf("from parent and x is: %d\n", --x);
    }
    printf("value of x is now: %d\n", x);
    return 0;

}
