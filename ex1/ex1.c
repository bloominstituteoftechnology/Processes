// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    int chfork = fork();

    if (chfork < 0)
    {
        printf("Fork Unsuccessful.\n");
    }
    else if (chfork == 0)
    {
        printf("Fork Successful with Child PID: %d\n", getpid());
        printf("X is currently: %d\n", x);
    }
    else
    {
        printf("Parent of Child with PID: %d\n", getpid());
        x = 200;
        printf("Parent is now: %d\n", x);
    }
    return 0;
}