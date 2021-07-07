// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Value of x in child process before modifying: %d\n", x);
        printf("child process with pid: %d\n", (int) getpid());
        x = 200;
        printf("x value in child: %d\n", x);
    } else {
        printf("parent process with pid: %d\n", (int) getpid());
        printf("x value in parent: %d\n", x);
    }

    printf("Final value of x: %d\n", x);
    return 0;
}
