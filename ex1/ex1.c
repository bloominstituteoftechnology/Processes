// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("first(pid: %d)\n", (int) getpid());
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("second, hello, child here (pid: %d) value of x = %d \n", (int) getpid(), x);
        x++;
        printf("Third, hello, child here (pid: %d) value of x = %d \n", (int) getpid(), x);
    } else {
        printf("Forth, hello, parent here (pid: %d) of child %d, value of x = %d\n", (int) getpid(), rc, x);
        x++;
        printf("Fifth, hello, parent here (pid: %d) of child %d, value of x = %d\n", (int) getpid(), rc, x);
    }
    return 0;
}
