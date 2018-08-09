// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The parent process is also called the "calling program"

int main(void)
{
    // Your code here
    int x = 100;
    printf("Hello, world! (pid: %d)\n", (int) getpid());

    // The fork() system call allow us to spawn or create a new child processes
    // "rc" stands for  "run command"?
    int rc = fork();

    if (rc < 0)
    {
        // The fprintf function sends formatted output to a stream
        // "stderr" stands for "standard error"
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    }

    else if (rc == 0)
    {

        printf("Hi, I am the child process (pid: %d) and my x variable has a value of %d.\n", (int) getpid(), x);
        x++;
        printf("Still the child process, and my x variable is now %d.\n", x);
    }
    
    else
    {
        printf("Hello, I am the parent process of %d (pid: %d) and my x variable has a value of %d.\n", rc, (int) getpid(), x);
        x--;
        printf("Still the parent process, and my x variable is now %d.\n", x);
    }

    return 0;
}