// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("Hello World (pid: %d)\n", (int) getpid());
    int rc = fork();

    if(rc < 0) 
    {
        fprintf(stderr, "fork failed\n"); //check for fork failure
        exit(1);
    } else if (rc == 0) 
    {
        printf("child process ran, (pid: %d), and x is: %d\n", (int) getpid(), x);
        x += 5; //changes the value of x if the child process runs.
        printf("child: x is now: %d\n", x);
    } else 
    {
        printf("parent of %d (pid: %d) ran, and x is %d\n", rc, (int) getpid(), x);
        x-= 5; //changes the value of x if the parent runs. 
        printf("parent: x is now: %d\n", x);
    }
    return 0;
}
