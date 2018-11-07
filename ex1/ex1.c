// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    printf("hello world (pid: %d); x = %d \n", (int) getpid(), x);
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        x = 99;
        printf("hello, child here (pid: %d); x = %d \n", (int) getpid(), x);
    } else {
        x = 101;
        printf("hello, parent here (pid: %d); x = %d\n", (int) getpid(), x);
    }

    printf("hello world again (pid: %d); x = %d \n", (int) getpid(), x);

    return 0;
}

// The parent process and the child process both get their own copy of variable x which can be independently updated.