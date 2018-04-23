// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable

// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?

// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here

    printf("--beginning of program\n");

    int x = 100;
    pid_t process = fork();

    if (process == 0)
    {
        int i = 0;
        for (; i < 5; ++i)
        {
            printf("Child process does this to x: %d \n", ++x);
        }
        printf("Child process PID - (pid: %d) \n", (int)getpid());
    }

    else if (process > 0)
    {
        int j = 0;
        for (; j < 5; ++j)
        {
            printf("Parent process does this to x: %d \n", ++x);
        }
        printf("Parent process PID - (pid: %d) \n", (int)getpid());
    }

    else
    {
        fprintf(stderr, "fork failed \n");
        exit(1);
    }

    printf("--end of program--\n");

    return 0;
}
