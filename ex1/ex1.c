// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    printf("The value of x (Initial): %d\n", x);
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failure\n");
        exit(1);
    } else if (rc == 0) {
        x /= 10;
        printf("child success (pid: %d) and altered value of x: %d\n", (int) getpid(), x);
    } else {
        x *= 10;
        printf("parent (pid: %d) of child (pid: %d) and altered value of x: %d", (int) getpid(), rc, x);
    }
    
    return 0;
}
