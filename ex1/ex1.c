// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x;
    int f = fork();
    if (f < 0)
    {
        printf("something bad happened");
    }
    else if (f == 0)
    {
        x = 200;
        printf("Child: value of x is %d\n", x); // 200
    }
    else
    {
        x = 100;
        printf("Parent: value of x is %d\n", x); // 100
    }
    // Forks have separate scopes from the parent
    return 0;
}
