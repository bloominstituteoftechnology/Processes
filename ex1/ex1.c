// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("sample hello (pid: %d)\n", (int) getpid());
    int x = fork();
    if (x < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (x == 0) {
            printf("hello, child here (pid: %d) \n", (int) getpid(), x);
    } else {
            printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), x);
        }
        return 0;
}