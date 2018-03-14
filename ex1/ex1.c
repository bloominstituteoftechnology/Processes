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
    printf("The value of x is %d and process id is %d\n",x,getpid());
    int child = fork();
    if (child == 0){
        x = 200;
        printf("The value of x in child is %d and piiid is %d and parentid is %d\n", x, getpid(), getppid());
    } else {
        printf("The value of x is %d and piiid is %d and parentid is %d\n", x, getpid(), getppid());
    }

    return 0;
}
