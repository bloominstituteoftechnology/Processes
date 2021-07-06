// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 333;
    printf("Parent: pid: %d\n", (int) getpid());

    int childProcess = fork();

    if (childProcess == 0) {
        printf("Child: pid: %d, x = %d\n", (int) getpid(), x);
        x++;
        printf("Child after x++, x = %d\n", x);
    } else {
        printf("Parent of %d, x = %d\n", childProcess, x);
        x--;
        printf("Parent after x--, x = %d\n", x);
    }

    return 0;
}
