// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

//77928 - parent
//77929 - child

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 77;
    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d), my value of x is: %d\n", (int) getpid(), x);
        x++;
        printf("child again, x is now: %d\n, x", x);
    }
    else {
        printf("hello, parent here (pid: %d) of child %d and my value of x is: %d\n", (int) getpid(), rc, x);
        x--;
        printf("parent again, x is now: %d\n, x", x);
    }

    printf("Value of x after the fork: %d\n", x);
    return 0;
}
