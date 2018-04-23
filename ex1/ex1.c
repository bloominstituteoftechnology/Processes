// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("hello, current value is: %d\n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork Failed\n"); 
        exit(1);
    } else if (rc == 0) {
        printf("Child x = %d \n", x);
        x = 77;
        printf("Child x = %d \n", x);
    } else {
        printf("Parent of child, x = %d\n", x);
        x = 88;
        printf("Parent of child, x = %d\n", x);
    }

    return 0;
}
