// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("starting fork program!\n");
    int x = 100;
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("\nhello, child here (pid: %d) \n", (int) getpid());
        printf("this is the value of x in the child scope: %d\n", x);
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("this is x in the parent scope: %d\n", x);
    }

    return 0;
}
