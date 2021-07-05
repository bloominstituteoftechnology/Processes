// Write a program that calls `fork()`. Before callin `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child proces?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>  // input and output functions
#include <stdlib.h> // more functions like malloc
#include <unistd.h> // provides access to the POSIX operating system API such as fork and pipe

int main(void) // define main which can be called without any parameter. Main is the first function that will be called when I run my program. It returns int values which will be used by OS to make some decisions based on it.
{
    int x = 100; // set a counter 100 at a parent
    printf("hello world (pid: %d\n", (int)getpid()); // print a message at a parent

    int rc = fork(); // copy the process.

    if (rc < 0) // if fork fails
    {
        fprintf(stderr, "fork failed\n"); // print out error message
        exit(1); // and stop the process
    }
    else if (rc == 0) // if fork is successful
    {
        printf("hello, I am child (pid: %d) and x is %d\n", (int)getpid(), x); // print out success message, process ID, and counter
        x++; // counter increment by 1
        printf("child again, x is now: %d\n", x); // print increased counter
    }
    else
    {
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int)getpid(), x); // print parent process process ID and counter
        x--; // decrese counter
        printf("parent again, x is now: %d\n", x); // print decreased counter
    }

    return 0; // 
}
