// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // initialize X to 100
    int X = 100;

    // set pointer to the memory location of X
    int *x = &X;

    // creates the fork and increments the PC, child will pickup after this line
    int rc = fork();

    // if rc is less than 0, no fork occurred
    if (rc <0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    // if the rc IS 0, you are in the child process (rc only increments for the parent to track the child)
    else if (rc == 0) {
        X +=5;
        printf("hello, child here, my x is valued at: %d\n", X);
    }

    // in all other cases, you are using the parent case.
    else {
        X += 10;
        printf("hello there, parent speaking, my x is valued at: %d\n", X);
    }

    return 0;
}
// the x variable, while copied from parent to child, are not actually the same instance of x. the processes have been duplicated, as have the variables. And while they're operating in the "same space", they don't truly refer to the "same" location in memory (despite the fact that they look like they do).
