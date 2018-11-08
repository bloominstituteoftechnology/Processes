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
    fork();
    printf("this is the print of x %d. at pid %d. \n", x, (int) getpid());
    //could put a fork to delineate further from parent and child.
    return 0;
}
