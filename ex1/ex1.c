// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("The value of x is: %d\n", x);
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Failed fork operation.\n");
        exit(1);
    } else if (rc == 0) {
        x = 50;
        printf("The child process (pid: %d): x-value is %d\n", (int) getpid(), x);
    } else {
        x = 25;
        printf("This parent process (pid: %d) of %d - x-value is %d\n", (int) getpid(), rc, x);
    }
    return 0;
}
