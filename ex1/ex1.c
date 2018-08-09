// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // allows us to use fork()

int main(void)
{
    int x = 100; // create x variable as per directions
    int rc = fork();

    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {  
        // child process satisfies this branch
        x = x+5;
        printf("the value of x for the child is %d \n", x);
    } else {
        x = x*10;
        printf("the value of x for the parent is %d \n", x);
    }
    return 0;
}