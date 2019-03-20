// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    // init x
    int x = 100;
    printf("Hello there, before we call fork(), this is our processID is: (pid: %d) \n", (int)getpid());
    printf("This is the parents value for x: %d \n", x);
    int rc = fork();

    if (rc < 0)
    {
        printf("Forking failed \n");
    }
    else if (rc == 0)
    {

        printf("Hello there, if rc==0, this is our child processID is: (pid: %d) \n", (int)getpid());
        printf("This is the childs value for x if rc==0: %d \n", x);
    }
     else
    {
        int x = 200;
        printf("hello, if rc > 0, this is parent here (pid: %d) of child %d\n", (int)getpid(), rc);
        printf("This is the childs value for x if rc > 0: %d \n", x);
    }

    return 0;
}
