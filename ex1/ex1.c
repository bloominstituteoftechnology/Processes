// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? -> They are the same
// What happens to the variable when both the child and parent change the value of x? -> they change independantly of each other.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("hello, I am child (pid: %d) and x is %d\n", (int) getpid(), x);
        x++;
        printf("child again, x is now: %d", x);
    } else{
        printf("hello, I am parent of pid: %d and x is %d\n", (int) getpid(), x);
        x--;
        printf("parent again, x is now %d\n", x);
    }

    return 0;
}
