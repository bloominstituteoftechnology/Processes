// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    //printf("From parent %d\n", x);
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("From child x =  %d\n", x);
        x++;
        printf("From child again x = %d\n", x);
        printf("From child fork() return =  %d\n", rc);
    } else
    {
        printf("From Parent fork() return =  %d\n", rc);
        printf("From Parent x =  %d\n", x);
        x--;
        printf("From Parent again x = %d\n", x);
    } 

    
    

    return 0;
}
