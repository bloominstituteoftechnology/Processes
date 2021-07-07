// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    printf("First pid: %d\n", (int) getpid());
    int rc = fork();
    int x = 100;

    if( rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc == 0) {
        printf("Child pid: %d and x: %d \n", (int)getpid(), x);
        x++;
        printf("Child pid: %d and x after increment: %d \n", (int)getpid(), x);
    }
    else {
        printf("Parent pid: %d of child %d and x: %d\n", (int) getpid(), rc, x);
        x--;
        printf("Parent pid: %d of child %d and x after decrement: %d\n", (int) getpid(), rc, x);
    }
    return 0;
}
