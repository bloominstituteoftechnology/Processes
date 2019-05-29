// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
// It seems to use the same starting value in both cases (the parent's pid).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int x = getpid();
    printf("Before fork: %d\n", x);

    int f = fork();
    if (f < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    x *= 10;

    printf("After fork: %d\n", x);
    
    return 0;
}
