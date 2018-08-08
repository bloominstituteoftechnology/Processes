// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Answer: Both the parent and the child are aware of the same value in x right after the fork.
// Neither the child nor the parent are aware when the other changes the value of x because there is
// no pipe communication between the two.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("x = %d in child before change\n", x);
        x = 50;
        printf("x = %d in child after change\n", x);
    } else {
        printf("x = %d in parent before change\n", x);
        x = 111;
        printf("x = %d in parent after change\n", x);
    }

    return 0;
}
