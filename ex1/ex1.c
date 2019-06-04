// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {  // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child id (pid: %d), x: %d\n", (int) getpid(), x);
        x += 20;
        printf("child, x + 20: %d\n", x);
    } else {
        printf("hello, parent id (pid: %d) of child %d, x: %d\n", (int) getpid(), rc, x);
        x += 10;
        printf("parent, x + 10: %d\n", x);
    }
    return 0;
}
