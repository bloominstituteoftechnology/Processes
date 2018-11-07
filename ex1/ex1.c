// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    printf("parent process: %d\n", getpid());
    int x = 100;
    int pid = fork();
    printf("X variable: %d - for process: %d\n", x, getpid());

    if(pid == 0) {
        printf("I'm a CHILD PROCESS: %d\n", getpid());
        x = 10;
    }
    else {
        printf("I'm a PARENT PROCESS: %d\n", getpid());
    }

    printf("I'm a process: %d, x is %d\n", getpid(), x);

    return 0;
}
