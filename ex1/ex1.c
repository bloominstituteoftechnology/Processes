// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork(); // fork initialized 
    if(rc < 0){
        fprintf(stderr, "fork failed\n"); //stderr is standard error stream, default destination for error messages
        exit(1);
    }else if(rc == 0){ // child process
        printf("Child fork (pid: %d) X: %d \n", (int) getpid(), x); 
        x = 20;
        printf("X Child fork reassigned: %d", x);
    }else{
        printf("Parent fork (pid: %d) of child \n", (int) getpid());
        x = 101; 
        printf("X Parent fork reassigned: %d", x); 
    }
    return 0;
}

// The value of the variable in the child process is the same to the value in the parent variable. 
// When the child changes the value of x it does not reflect on the parent fork. The variables no longer point to the same value. 
