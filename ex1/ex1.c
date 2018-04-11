// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("Parent pid: %d\n", (int) getpid());

    int childProcess = fork();

    if (childProcess < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (childProcess == 0) {
        printf("Child pid:%d and x is %d\n", (int) getpid(), x);
        x++;
        printf("Child new value is now: %d\n", x);
    } else {
        printf("Parent of child with (pid: %d) and x is: %d\n", childProcess, (int) getpid(), x);
        x--;
        printf("Parent new value is now %d\n", x);
    }
    return 0;
}
