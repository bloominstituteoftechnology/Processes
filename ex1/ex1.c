// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
    // --> the value of x is the same for the parent and the child
// What happens to the variable when both the child and parent change the value of x?
    // --> the value of x changes to the value that was assigned in each instance;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("hello world (pid: %d, x: %d)\n", (int) getpid(), x);

    int rc =fork();

    if (rc < 0) {
        printf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 200;
        printf("hello, child here (pid: %d, x: %d)\n", (int) getpid(), x);
    } else {
        x = 300;
        printf("hello, parent here (pid: %d, x: %d) of child %d\n", (int) getpid(), x, rc);
    }
     
    return 0;
}
