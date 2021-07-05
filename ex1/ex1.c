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
    int rc = fork();

    if (rc < 0) {
        printf("%d", x);

    } else if (rc == 0) {
        x = 10;
        printf("Child Process (pid: %d) X = %d \n", (int) getpid(), x);
    } else {
        x = 11;
        printf("Parent Process (pid: %d) of child %d. X = %d \n",  (int) getpid(), rc, x);
    }

    printf("X = %d \n", x);

    return 0;
}


//Fork - To create a clone of the calling process. 
// The clone of the process starts executing right after the fork call
//If fork returns 0 it is in a child process
//