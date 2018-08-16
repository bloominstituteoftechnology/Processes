// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

/*
> What value is the variable in the child process?

The value of the variable in the child process is the same in the parent before any reassignment

 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int hot_var = 100; // starting variable
    int rc = fork(); // fork() duplicates the process
    if (rc < 0){ // if the fork() fails, we exit the program
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc == 0){
        //hot_var = 0;
        printf("The value of hot_var is 0\n", hot_var); //if it equals 0, we stick with the parent
    }
    else {
        hot_var = 69;
        printf("The value of hot_var is %d\n", hot_var);// if fork() returns a PID above 0, the child will prodice a different output
    }

    return 0;
}
