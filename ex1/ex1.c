// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 1;
    int rc = fork();
    if (rc < 0)
    {
        printf("failure!");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child!\n");
        printf("%d\n", x);
        x = 5;
        printf("%d\n", x);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent!\n");
        printf("%d\n", x);
        x = 10;
        printf("%d\n", x);
    }

    return 0;
}
