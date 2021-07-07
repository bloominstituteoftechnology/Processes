// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

        printf("Parent PID: %d, x = %d \n", (int)getpid(), x);

        int rc = fork();

        if (rc == 0)
        {
            printf("Fork successful. We are the child process.\n Child PID: %d, Parent PID: %d", getpid(), getppid());
        }
        else if (rc > 0)
        {
            printf("We are the parent process.\n Parent PID: %d of Child PID: %d", getpid(), rc, x);
        }
        else
        {
            printf(stderr, "Fork failed");
        }

    return 0;
}
