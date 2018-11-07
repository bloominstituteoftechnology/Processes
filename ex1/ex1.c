// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    
    if(pid == 0){
        printf("Child\n");
    }else{
        printf("Parent is waiting\n");
        wait(NULL);
        printf("Parent\n");
    }
    return 0;
}
