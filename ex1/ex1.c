// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int variable = 0;
    // Your code here
    printf("pid: %d\n", (int)getpid());
    variable = 100;

    int rc = fork();
    if(rc < 0){
        printf("Fork failed! U stoopid?!\n");
    }else if (rc == 0){
        variable = 25;
        printf("hello, child here (pid: %d) \n", (int) getpid());
        printf("variable in child process: %d\n", variable);
        exit(0);
    }else{
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("parent level var: %d\n", variable);
    }
    return 0;
}
