// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    
    printf("Parent process (pid: %d)\n", (int) getpid());
    
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        x = 1000;
        printf("hello, child here (pid: %d) \n", (int) getpid());
        printf("x is %d \n", x);
    } else {
        x = 1;
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("x is %d\n", x);
    }
    return 0;
}
