// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x??

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 12;
    int y = fork();

    if (y < 0) {
        printf("Fork Failed\n");
    } else {
        if (y == 0) {
            printf("I am the child process and the value of x is: %d\n", x);
        }
        else {
            printf("I am the parent process and the value of x is: %d\n", x);
        }
    }
    return 0;
}
