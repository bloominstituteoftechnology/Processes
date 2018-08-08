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
    printf("starting value of x: %d (pid: %d)\n", x, (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d) \n", (int) getpid());
        x = 13;
        printf("child x is now %d\n", x); // x is 13
    } else {
        printf("Parent of %d, (pid: %d),  x is %d \n", rc, (int) getpid(), x);
        x = 58;
        printf("Parent x is now %d\n", x); //x is 58
    }

    return 0;
}

// x is defined separately in Parent and child, so changes in Parent to don't affect child after fork and vice versa