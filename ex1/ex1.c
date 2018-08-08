// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    // The fork() system call allow us to spawn or create new child processes
    // rc = "run command"?
    int rc = fork();

if (rc < 0)
{
    // The fprintf function sends formatted output to a stream
    // "stderr" stands for standard error
    fprintf(stderr, "Fork failed!\n");
    exit(1);
}
else if (rc == 0)
{
    printf("Child variable x is equal to %d\n", x);
    x = 50;
    printf("Child variable x is equal to %d\n", x);
}
else
{
    printf("Parent variable x is equal to %d\n", x);
    x = 150;
    printf("Parent variable x is equal to %d\n", x);
}
    return 0;
}