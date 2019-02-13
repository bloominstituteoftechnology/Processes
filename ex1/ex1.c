// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int x = 50;
    int n = fork();
    if (n == 0)
    {
        x = 20;

        printf("%i\n", x);
    }
    else if (n > 0)
    {
        x = 100;
        printf("%i\n", x);
    }

    return 0;
}