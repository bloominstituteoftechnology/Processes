// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


//a. The value of x in the child process is 100 (updated value)
//b. It seems that when a process if forked, the variables for the child and the parent
// are the ones that were set before the fork and changes made in one process doesn't 
// effect the variables in the other process. Proving that processes are indeed independent.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 5;
    printf("Initial value of x: %d\n", x);

    x = 100;
    printf("Updated value of x: %d\n\n", x);

    pid_t pid = fork();

    if (pid < 0) //fork failed
    {
        exit(1);
    } 
    else if (pid == 0) //child process
    {
        printf("CHILD: Initial Value of x in the child process: %d\n", x);
        //Child will set x to 100;
        x = 150;
        printf("CHILD: Updated Value of x in the child process: %d\n\n", x);
    }
    else {
        //this is the parent process
        //Parent makes x = 50
        printf("PARENT: Initial Value of x in the parent process: %d\n", x);
        x = 50;
        printf("PARENT: Updated Value of x in the parent process: %d\n\n", x);
    }

    return 0;
}
