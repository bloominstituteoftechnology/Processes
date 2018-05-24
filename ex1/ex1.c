// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ERROR_FORK[] = "System failed to execute fork()!";
char CHILD[] = "Halved variable after fork!";
char PARENT[] = "My variable before any half-life";

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    int y;
    int fX = fork();

    if (fx < 0)
    {
        printf("%S", ERROR_FORK);
    }
    else if (fx == 0)
    {
        y = x / 2;
        printf("%s, %d", CHILD, y);
    }
    else
    {
        printf("%s, %d", PARENT, x);
    }

    return 0;
}
