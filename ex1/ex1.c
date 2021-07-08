// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 120;

    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();

    printf("%d\n", rc);

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child (pid: %d) and x is: %d\n", (int) getpid(), x);
        x = x * 2;
        printf("child x * 2 is now: %d\n", x);
    } else {
        printf("parent of child %d here (pid: %d) and x is: %d\n", rc, (int) getpid(), x);
        x = x / 2;
        printf("parent again, x / 2 is: %d\n", x);
    }

    return 0;
}
