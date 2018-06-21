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
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d) \n", (int) getpid());
        x = 10;
        printf("x equals: %i\n", x);
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        x = 120;
        printf("parent x equals: %i\n", x);
    }

    return 0;
}
