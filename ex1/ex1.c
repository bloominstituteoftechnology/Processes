// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 42;

    x = x % 5 + 3;
    printf("X is now %d\n", x);
    // Your code here
    int rc = fork();

    if (rc < 0)
    {
        printf("Something SUUUUPER Bad happened..");
        exit(1);
    }
    else if ( rc == 0 )
    {
        printf("The child branch says x is equal to %d\n", x);
        x = 33;
        printf("but now it should equal 33: %d\n", x);
    }
    else
    {
        printf("The Parent branch says x is equal to %d\n", x);
        x = 12;
        printf("but now it should equal 12: %d\n", x);
    }

    return 0;
}

//it appears the xs are separate
