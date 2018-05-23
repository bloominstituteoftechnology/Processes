// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int forker(int x)
{
    printf("hello world (pid:%d) \n", (int) getpid());
    int rc = fork();
    if (rc < 0) 
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0 )
    {
        printf("hello, I am child (pid:%d\n", (int) getpid());
        ++x;
        printf("Child forked x val: %d\n", x);
    }
    else
    {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        --x;
        printf("Parent forked x val: %d\n", x);
        
    }
}

int main(int argc, char *argv[])
{
    // Your code here

    int x = 40;
    ++x;
    printf("Main x val: %d\n", x);
    forker(x);

    return 0;
}
