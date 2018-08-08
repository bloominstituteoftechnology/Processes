// Write a program that calls `fork()`. Before calling `fork()`, 
//have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 
//What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    printf("Hello World! (pid: %d, x: %d)\n", (int) getpid(), x);
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        printf("hello, child here (pid: %d, x: %d)\n", (int) getpid(), x + 1);
    }
    else{
        printf("hello, parent here (pid: %d, x: %d) of child (pid: %d\n, x: %d)\n", (int) getpid(), x, rc, x+1);
    }

    return 0;
}
