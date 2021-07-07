// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int num = 10;
    printf("My variable i access is \n", (int) getpid(), num);
    // Your code here
    // calls fork 

    int rc = fork();

    if(rc < 0) { // fork failed exit

        exit(1);
    }  else if (rc == 0) { //child process runs this branch
        printf("My value is \n", (int) getpid(), rc);
    } else {
        printf("Hello, parent here (pid: %d) of child \n", (int) getpid(), rc);
    }

    return 0;
}
