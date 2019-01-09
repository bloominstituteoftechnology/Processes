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

    printf("Before fork, pid is %d\n", (int) getpid());

    int rc = fork();

    if (rc == 0) {
        printf("Child: pid is %d and x is %d\n", (int) getpid(), x);
        x++;
        printf("Child after increment: pid is %d and x is %d\n", (int) getpid(), x);
    } else if (rc > 0) {
        printf("Parent: pid is %d and x is %d\n", (int) getpid(), x);
        x++;
        printf("Parent after increment: pid is %d and x is %d\n", (int) getpid(), x);
    }

    return 0;
}
