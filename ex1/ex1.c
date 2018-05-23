// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("Hello World (pid: %d)\n", (int)getpid());
    int x = 42;

    int rc = fork();
    x = 44;
    if (rc < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        x = 90;
        printf("hello, child here (pid: %d) (x: %d)\n", (int)getpid(), x);
    }
    else if (rc > 0)
    {
        printf("hello, parent here (pid: %d) (of child: %d) (x: %d)\n", (int)getpid(), rc, x);
    }

    return 0;
}
