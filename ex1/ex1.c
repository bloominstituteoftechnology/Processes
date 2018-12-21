// Write a program that calls `fork()`. Before calling `fork()`, 
// have the main process access a variable (e.g., x) and set its 
// value to something (e.g., 100). What value is the variable in 
// the child process? What happens to the variable when both the
// child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// -value of variable n child process is the same as the one 
//  assigned in parent process
// -when x is changed in the child and parent, the value of
//  x reflects the changed x in the child and parent processes,
//  respectively.

int main(void)
{
    int x = 349;
    int f = fork();
    if (f < 0) {
        fprintf(stderr, "fork failed\n");
    }
    else if (f == 0) {
        printf("child x = %i\n", x);
        x = 990;
        printf("child x (changed) = %i\n", x);
    }
    else {
        printf("parent x = %i\n", x);
        x = 50;
        printf("child x (changed) = %i\n", x);
    }

    return 0;
}
