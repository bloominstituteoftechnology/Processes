// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x;
    int f = fork();
    if (f < 0) // if fork less than 0, print error
    {
        printf("something is not right.");
    }
    else if (f == 0) // if fork equals 0, set variable and print child
    {
        x = 200;
        printf("child: value of x is %d\n", x); // 200
    }
    else // set variable and print parent
    {
        x = 100;
        printf("Parent: value of x is %d\n", x); // 100
    }
    // separate scopes from the parent
    return 0;
}
