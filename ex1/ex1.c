// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child pid: %d\n", (int) getpid());
        printf("the value of x in child is %d\n", x);
        // value of x is still 100; it has the value that it had before forking.
        x += 100;
        printf("after adding 100 in child: %d\n", x);
    } else {
        printf("parent pid: %d, child pid: %d\n", (int) getpid(), rc);
        printf("the value of x in parent is %d\n", x);
        // value of x is 100
        x += 100;
        printf("after adding 100 in parent: %d\n", x);
    }
}
