// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

//What value is the variable in the child process? The variable == 0
//What happens to the variable when both the child and parent change the value of x? the variable value would be scoped to the local process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc == 0) {
        x ++;
        printf("Child process (pid: %d) and x: %d\n", (int) getpid(), x);
    } else {
        x--;
        printf("Parent process (pid: %d) of child process %d and x: %d\n", (int) getpid(), rc, x);
    }

    return 0;
}
