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
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Child process failed.\n");
        exit(1);
    } else if (rc == 0) {
        printf("x value before child process: %d\n", x); //value not changed, equal to parent

        x = 50;

        printf("x value after child process: %d\n", x); //value changed but does not affect parent's value
    } else {
        printf("x value before parent process: %d\n", x); //value not changed, equal to child

        x = 75;

        printf("x value after parent process: %d\n", x); //value changed but does not affect child's value
    }

    return 0;
}
