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
    int rc = fork();
    x = 99;
    printf("x: %d\n", x);
    if (rc == 0)
    {
        printf("child: (pid: %d) \n", (int)getpid());
        x = 22;
        printf("x should be 22 in child: %d\n", x);
    }
    else
    {
        printf("parent (pid: %d) of child %d \n", (int)getpid(), rc);
        x = 33;
        printf("x should be 33 in parent: %d\n", x);
    }

    return 0;
}
