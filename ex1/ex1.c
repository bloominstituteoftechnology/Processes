// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x? They both increment by one w x++

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100; 
    printf("Hello world (pid: %d)\n", (int) getpid()); 
    int rc = fork(); 

    if (rc < 0) {
        fprintf(stderr, "fork failed\n"); 
        exit(1); 
    } else if (rc == 0) {
        printf("Hello, child here (pid: %d) \n", (int)
        getpid(), x); 
        x++; 
        printf("Child's updated x is: %d \n", x); 
    } else {
        printf("Hello, parent here (pid: %d) \n", (int)
        getpid(), rc, x); 
        x++; 
        printf("Parent updated x is: %d \n", x); 
    }

    return 0;
}
