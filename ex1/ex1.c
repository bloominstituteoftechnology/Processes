// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    printf("Hello World (pid: %d)\n", (int)getpid());

    int rc = fork();

    if (rc < 0) // Error
    {
        fprintf(stderr, "Fork has failed\n");
        exit(1);
    }
    else if (rc == 0) // Child
    {
        printf("Child (pid: %d) and x is %d\n", (int)getpid(), x);
        x++;
        printf("Child again x is now: %d\n", x);
    }
    else // Parent
    {
        printf("Parent of %d (pid: %d) and x is %d\n", rc, (int)getpid(), x);
        x--;
        printf("Parent again x is now %d\n", x);
    }

    return 0;
}
