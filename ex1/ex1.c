// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x=100;

    int y = fork();

    if (y==0) {
        x=200;
        printf("in the child process, x is %d\n", x);
    } else {
        x = 10;
        printf("in the parent process, x is %d\n", x);
    }

    printf("X is set to %d\n", x);

    return 0;
}
