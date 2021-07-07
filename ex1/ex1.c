// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? The initial value when the variable was declared.
// What happens to the variable when both the child and parent change the value of x? The variable holds different values in separate processes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("Parent, pid: %d\n", getpid());
    int rv = fork();
    int val;

    if(rv < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rv == 0)
    {
        printf("Child, pid: %d, val: %d\n", getpid(), val);
        val = 50;
        printf("Child, pid: %d, val: %d\n", getpid(), val);
    }
    else
    {
        int wc = waitpid(rv, NULL, 0);
        printf("Parent, pid: %d, val: %d\n", getpid(), val);
        val = 100;
        printf("Parent, pid: %d, val: %d\n", getpid(), val);
    }
    
    return 0;
}
