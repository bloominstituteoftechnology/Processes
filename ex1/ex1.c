// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // Your code here
    int some_digit = 9999;
    printf("pre fork: %d\n", some_digit);
    int pid = -1;
    pid = fork();
    printf("post fork: %d\n", some_digit);
    some_digit = pid;
    printf("post fork changed to pid: %d\n", some_digit);
    return EXIT_SUCCESS;
}
