// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    printf("pre-fork: parent pid %d, x = %d \n", (int)getpid(), x);

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("post-fork: child pid %d, x = %d \n", (int)getpid(), x);
    }
    else
    {
        printf("post-fork: parent pid %d of child %d, x = %d\n", (int)getpid(), rc, x);
    }

    return 0;
}
