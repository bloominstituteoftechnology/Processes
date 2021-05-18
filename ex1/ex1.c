// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 0;
    // Your code here
    pid_t rc = fork();
    
    if(rc == 0) {
        x = 200;
        printf("Child x is %d\n", x)"
    } else {
        x = 500;
        sleep(1);
        printf("Parent!\n";
    }
    return 0;
}
