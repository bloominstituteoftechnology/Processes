// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// In the program below, the parent process decrements and the child process increments. Because they are two separate processes running the 
// code independently, x = 99 for the parent and x = 101 for the child.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        x++;
    }
    else {
        x--;
    }
    printf("%d, %s, %d\n", pid, "hello", x);

    return 0;
}
