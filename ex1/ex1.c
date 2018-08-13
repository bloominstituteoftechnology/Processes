// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    // both child and parent will get their own copies of `x` after fork
    // and hence both can change the value of their corresponding `x` without affecting each other
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        x = 10;
        printf("Hello, child here (pid:%d), x = %d\n", (int) getpid(), x);
    }
    else {
        x = 50;
        printf("Hello, parent here (pid:%d) of child %d, x = %d\n", (int) getpid(), rc, x);
    }

    return 0;
}
