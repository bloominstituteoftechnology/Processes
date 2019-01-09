// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 

// What value is the variable in the child process?
// 100, or the value before calling the fork.

// What happens to the variable when both the child and parent change the value of x?
// It exists in two process states, and can hold different values.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;

    int forked = fork();


    if(forked < 0){
        fprintf(stderr, "Fork attempt failed.\n");
        exit(1);
    } else if(forked == 0){ // if the fork runs with no errors, do some value checks.
        printf("Child x is: %d\n", x);

        x = 20;

        printf("New child x is: %d\n", x);
    } else {
        wait(NULL);
        printf("Parent x is: %d\n", x);

        x = 50;
        
        printf("New parent x is: %d\n", x);
    }

    return 0;
}
