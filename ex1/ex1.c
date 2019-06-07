// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    printf("hello world!\n");
    int x = 101;
    int fp = fork();
    if (fp < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fp == 0)
    { // child process satisfies this branch
        printf("x is: %d \n", x);
        x = 102;
    }
    else
    {
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), fp);
    }



    return 0;
}
