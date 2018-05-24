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
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc == 0)
    {

        printf("Child process PID - (pid: %d) \n", (int)getpid());
    }

    else
    {
        printf("Parent process PID - (pid: %d) \n", (int)getpid());
    }

    int i = 0;
    for (; i < 5; ++i)
    {
        printf("Child process does this to x: %d \n", ++x);
    }
    printf("--end of program--\n");

    return 0;
}
