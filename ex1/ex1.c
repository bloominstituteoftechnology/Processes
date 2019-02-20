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
    int my_fork = fork();

    if (my_fork == 0) {
        printf("x is %d\n", x);
        x = 111;
        printf("x is now %d\n", x);
    }
    if (my_fork > 0 ) {
        printf("x is %d\n", x);
        x = 222;
        printf("x is now %d\n", x);
    }
    if (my_fork < 0) {
        printf("Error!");
    }


    return 0;
}
