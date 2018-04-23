// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable

// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?

// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int process = fork();
    // Your code here
    if (process < 0)
    {
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (process == 0)
    {
        int i = 0;
        for (; i < 5; ++i)
        {
            printf("Child process does this to x: %d, (pid: %d) \n", x, (int)getpid());
        }
    }
    else
    {
        int j = 0;
        for (; j < 5; ++j) {
            
        }
        printf("Parent process does this to x: %d, (pid: %d) \n", x, (int)getpid());
    }
    return 0;
}
