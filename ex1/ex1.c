// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;                                      // declare a variable
    printf("hello world (pid: %d)\n", (int)getpid()); // get process id of parent

    int rc = fork(); // call fork function

    if (rc < 0) // 0 represents child function
    {
        fprintf(stderr, "fork failed\n");
        exit(1); // 1 represents error value
    }
    else if (rc == 0) // 0 represents success
    {
        printf("hello, I am child (pid: %d) and x is: %d\n", (int)getpid(), x);
        x++; // count
        printf("child again, x is now: %d\n", x);
    }
    else // if not child
    {
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int)getpid(), x);
        x--;
        printf("parent again, x is now: %d\n", x);
    }

    return 0;
}
