// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    // Your code here
    int x = 100;
    printf("Hi im x. My value is: %d\n", x);
    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork(); // --> Child process starts here :D || parent process gets the Child's PID

    if (rc < 0) { // fork fail --> Child process didn't recieve 0
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // satisfied --> Child process always receives 0 if fork is successful        
        printf("hello world, child (pid: %d)\n", (int) getpid());        
    } else {        
        printf("hello world, parent (pid: %d) of child %d\n", (int) getpid(), rc);        
    }

    return 0;
}
