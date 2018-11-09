// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    pid_t pid;
    int x = 100;
    pid = fork();
    // ------------------------------------------------ child process starts executing here
    if (pid < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    { // child process satisfies this branch
        x = 25;
        printf("Hello,children (%d) \n", x);
    }
    else
    {
        x = 50;
        printf("PARENTALS (%d) \n", x);
    }
    printf("final value: (%d) \n", x);
    return 0;
}