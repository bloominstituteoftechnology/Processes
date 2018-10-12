// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    // Your code here
    int x = 800;
    printf("X at the moment is what value %d\n", x);

    pid_t pid = fork();

    if (pid == 0) {
        printf("What is the value of x child process, (x:%d) (pid:%d)\n", x, getpid());
    } else {
        x = 100;
        printf("This is the parent process and the value of X is %d\n", x);
    } 

    return 0;
}
