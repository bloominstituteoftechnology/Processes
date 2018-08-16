// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) // main function that will return an int and receives no parameters
{
    // Your code here
    int x = 100; // before the forking occurs we are setting a variable with a variable of 100 to be able to track how the value changes in the parent and child respectively.
    printf("hello world (pid: %d)\n", (int)getpid());

    int rc = fork(); // used by a parent process to create a new child process that will start executing right after the fork() is called.

    if (rc < 0) // fork was unsuccessful
    {
        fprintf(stderr, "fork failed\n"); // print the error to the console that the fork failed
        exit(1);                          // exit
    }
    else if (rc == 0) //child process receives 0 if the fork() call was successful, so if rc == 0 then the fork was sucessful and specifically the child process satisfies this criteria
    {
        printf("hello, I am child (pid: %d) and x is: %d\n", (int)getpid(), x);
        x++; // see how child changes variable value by incrementing the value of x
        printf("child again, x is now: %d\n", x);
    }
    else // parent process receives the PID (process identifier) of the child process it just spawned which is neither 0 nor < 0
    {
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int)getpid(), x);
        x--; // see how parent changes variable value by decrementing the value of x
        printf("parent again, x is now: %d\n", x);
    }

    return 0; // need to return an integer
}
