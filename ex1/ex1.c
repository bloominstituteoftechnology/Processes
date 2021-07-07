// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x=100;
    pid_t pid = fork();
    //x = 101;
    if (pid ==0){
        x = 102;
        printf("Child process x = %d\n", x);
    }
    else {
        x = 103;
        printf("Parent process x = %d\n", x);
    }
    return 0;
}
