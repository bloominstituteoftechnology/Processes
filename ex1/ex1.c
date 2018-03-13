// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int n = 100;
    printf("Parent Here: (pid: %d)\nThe Value of n is: %d\n", (int)getpid(), n);
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Fork Failed\n");
    }
    else if (rc == 0)
    {
        printf("Child Here: (pid: %d)\nThe Value of n is: %d\n", (int)getpid(), n);
    }
    return 0;
}
