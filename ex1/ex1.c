// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // init x with a value of 100
    int x = 100;
    // print hello world, with a process identifier
    // getpid()= pid = process identifier
    printf("Hello World (pid: %d)\n", (int) getpid());
    // set the fork function on a variable named rc
    // The fork() system call is used by a parent process to create a new child process
    int rc = fork();

    if (rc < 0 )
    {
        // if the fork has a negative vale, give a standard error(stderr) message
        // fprintf = sends formatted output to a stream
        fprintf(stderr, "fork failed\n");
        // then, exit the block
        exit(1);
    }
    else if (rc == 0)
    {
        // child process satisfies this branch
        printf("hello, child here (pid: %d) and x is: %d\n", (int) getpid(), x);
        // increment x's value
        x++;
        // let the user know what x's update value is
        printf("1Child again, x is now: %d\n", x);
    }
    else
    {
        // the child process is a positive integer
        printf("hello, parent of child %d here (pid: %d) and x is: %d\n", rc, (int) getpid(), x);
        // decrement x's value
        x--;
        // I add the 2 at the start of the string to identify the order in which
        // these are printed. This one is printed first. 
        printf("2Child again, x is now: %d\n", x);
    }
    return 0; 
}
