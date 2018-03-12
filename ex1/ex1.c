// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int testValue = 1337;

    int child = fork();

    if (child < 0) 
    {
        printf("Unable to fork a child\n");
        exit(1);
    } else if (child == 0)
    {
        testValue = 1001;
        printf("Inside the child, the value of testValue is: %d\n", testValue);
    } else
    {
        int wait = waitpid(child, NULL, 0);
        printf("Inside the parent, the value of testValue is: %d\n", testValue);
    }

    return 0;
}
