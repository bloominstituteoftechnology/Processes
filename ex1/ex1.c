// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("Hello! I am the parent and my pid is %d\n", getpid());

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am the child; my pid is %d, and x = %d\n", getpid(), x);
        x = 2;
        printf("I am the child; my pid is %d, and x = %d\n", getpid(), x);
    } else {
        printf("I am the parent and I say that x = %d\n", x);
        x = 99;
        printf("I am the parent and I say that x = %d\n", x);
    }

    return 0;
}

