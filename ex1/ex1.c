/* Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x? */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100; // before calling `fork()`, have the main process access a variable and set its value (e.g., x = 100)
    int rc = fork(); // create rc variable and set it equal to fork

    if (rc < 0) {    // fork failed
        fprintf(stderr, "fork failed\n"); // error message
        exit(1); // exit 
    } else if (rc == 0) {
        x = x/2;
        printf("hello, child here (x: %d) and (pid: %d) \n", x, (int) getpid());
    } else {
        x = x*2;
        printf("hello, parent here (x: %d) and (pid: %d) of child %d\n", x, (int) getpid(), rc);
    }
    return 0;
}
