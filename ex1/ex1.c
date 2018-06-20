// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        printf("Fork failed\n");
    } else if (rc == 0) {
        printf("Child (pid: %d)", (int) getpid());
    } else {
        printf("Parent (pid: %d) of child %d \n", (int) getpid(), rc);
    }
    // Your code here

    return 0;
}
