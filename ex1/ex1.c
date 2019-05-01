// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// The variable is copied in the child process, so it stays the same.

// What happens to the variable when both the child and parent change the value of x?
// They will have their own separate values and they can be different.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    //before calling fork have the main process access a variable
    //an set its value to something.
    int x = 100;
    //call the fork
    int called_fork = fork(); //returns 1 or 0

    if(called_fork == 0)
    {
        printf("I'm the child! %d\n", x);
    } else {
        printf("I'm the parent! %d\n", x);
    }

    return 0;
}
