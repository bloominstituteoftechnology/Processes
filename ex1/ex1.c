// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Answer: At the start the child process has the same value (100).
// When changed the variable has two values one on the main thread and one on the forked thread.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

    int x = 100;

    if (x == 100){
        int new_process = fork();
        if (new_process){
            printf("CP has same value as MP: %d\n", x);
            printf("Child process will now change the val: ");
            x = 10;
        }
    
    }
    printf("From main process the value is left the same: %d\n", x);

    return 0;
}
