// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    //main process has access to (x=100)
    //set variable rc equal to our fork
    int x = 100;
    int rc = fork();

    printf("generate pid (pid: %d)\n", (int)getpid());
//there is no fork if < 0
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    //child process
    else if (rc == 0)
    {
        printf("child (pid: %d) and x is: %d\n", (int)getpid(), x);
        //change in the variable(child)
        x++;
        printf("child, x is now: %d\n", x);
    }
    //parent process
    else
    {
        //change in the variable(parent)
        x = x - 2;
        printf("parent (pid: %d) of this child %d (x:%d)\n",(int)getpid(),x);
        
        
    }

    
    return 0;
}