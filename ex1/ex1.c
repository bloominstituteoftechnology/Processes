// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

/*
> What value is the variable in the child process?


> What happens to the variable when both the child and parent change the value of x?


*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int hot_var = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        hot_var = 0;
        printf("The value of hot_var is ICE COLD, BRUH! %i DEGREEEES\n", hot_var);
    } 
    else {
        hot_var = 69;
        printf("The value of hot_var is %i\n", hot_var);
    }
    
    return 0;
}
