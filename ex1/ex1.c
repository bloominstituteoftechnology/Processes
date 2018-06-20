// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

/* value of the identical variable is different for both child and parent. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// argc is the argument count
// argv is an arry of character pointers to argument themselves.
int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) // if fork fails;
    {
        fprintf(stderr, "forkfailed\n");
        exit(1);
    }
    else if (rc == 0) // child process;
    {
        int x = 100;
        printf("I am child, x = %d \n", x);
    }
    else // parent process;
    {
        int x = 200;
        printf("I am parent, x = %d \n", x);
    }

    return 0;
}
