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

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Value of x in the child process is: %d, pid is: %d\n", x, (int)getpid()); // 100
        x++;
        printf("The CHILD incremented x, and its value is: %d\n", x); // 101
    }
    else
    {
        printf("Hello from the parent process! pid is: %d\n", (int)getpid());
        printf("Value of x in the parent process is: %d\n", x); // 100
        x = 200;
        printf("The PARENT set x's value to %d\n", x);
        printf("Value of x in the parent process is: %d\n", x); // 200
    }

    return 0;
}
