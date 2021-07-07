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

    printf("(pid: %d) The initial value of x is: %d\n", (int) getpid(), x);

    int rc = fork();
    // child process starts executing here.
    // if rc < 0 which means no child --> fail
    // if rc == 0 there is a child.
    // then process
    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x += 50;
        printf("Child here (pid: %d): x value is %d\n", (int) getpid(), x);
    }
    else
    {
        x += 100;
        printf("Parent here (pid: %d): x value is %d\n", (int) getpid(), x);
    }
    return 0;
}
