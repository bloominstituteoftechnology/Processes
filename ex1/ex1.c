// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Answer: The x value use by default in both the parent and child, set to the initial = 100; however, if
// it is changed inside the child process (e.g. its particular if...else block), then the value of x
// inside the process is used.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("initial parent x value: %d\n", x);
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n"); // #QUESTION: fprintf vs printf? ==> https://stackoverflow.com/questions/4627330/difference-between-fprintf-printf-and-sprintf
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        x = 101;
        // printf is equivalent/short-hand to writing `fprintf(stdout,...)`
        printf("child x value: %d\n", x);
    }
    else
    {
        x = 99;
        printf("new parent x value: %d\n", x);
    }

    return 0;
}
