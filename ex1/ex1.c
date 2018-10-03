// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? The value when the variable was declared. 
// What happens to the variable when both the child and parent change the value of x? The variable holds different values in each process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    printf("Parent, pid: %d\n", getpid());
    int rv = fork();
    int x = 20;

    printf("Parent, pid: %d\n", getpid());
    if (rv < 0)
    {
        printf(stderr, "unable to fork\n");
        exit(1);
    }
    else if(rv == 0)
    {
        printf("Child, pid: %d, x: %d\n", getpid(), x);
        x = 50;
        printf("Child, pid: %d, x: %d\n", getpid(), x);
    }
    else 
    {
        int wc = waitpid(rv, NULL, 0);
        printf("Parent, pid: %d, x: %d\n", getpid(), x);
        x = 100;
        printf("Parent, pid: %d, x: %d\n", getpid(), x);
    }

    return 0;
}