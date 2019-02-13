// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("%d\n", x);
    int rc = fork();

    if (rc < 0)
    {
        printf("Fork failed\n");
    }
    else if (rc == 0)
    {
        x += 2;
        printf("After child change: %d\n", x);
    }
    else
    {
        x += 10;
        printf("After parent change: %d\n", x);
    }

    return 0;
}
