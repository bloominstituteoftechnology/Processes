// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// References:
// fork():  https://www.geeksforgeeks.org/fork-system-call/
// fprintf():  https://www.geeksforgeeks.org/fprintf-in-c/

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
        x = 200;
        printf("child, x value: %d\n", x);
    } else {
        x = 300;
        printf("parent, x value: %d\n", x);
    }

    printf("last x value: %d\n", x);

    return 0;
}
