// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("Before the fork, x is %d.\n", x);
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    } else if (pid == 0) {
        x = 200;
        printf("Child process, process is %d, x is %d.\n", (int) getpid(), x);
    } else {
        x = 300;
        printf("Parent process, process is %d, x is %d.\n", (int) getpid(), x);
    }

    printf("At the end, x is %d.\n", x);
    return 0;
}
