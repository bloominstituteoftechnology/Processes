// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    int rc = fork();
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) { // child process satisfies this branch
        x = 40;
        printf("hello, child here, x = %d \r\n", x);
    
    }else{
        x = 400;
        printf("hello, parent here, x = %d \r\n", x);
    }

    return 0;
}
