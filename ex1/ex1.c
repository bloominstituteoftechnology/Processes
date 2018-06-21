// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Answers: The child and parent retain the values in their variables since fork() is only creating a copy of the parent process. They cannot affect each other's data.

// Random link: https://en.wikipedia.org/wiki/Standard_streams#1970s:_C_and_Unix

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 50;
    int rc = fork();

    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x = 7;
        printf("Child x value: %d\n", x);
    }
    else
    {
        x = 3;
        printf("Parent x value: %d\n", x);
    }
    return 0;
}
