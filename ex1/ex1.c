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
    printf("hello world (pid: %d)\n", (int)getpid()); // prints the pid along with hello world

    int rc = fork(); // sets rc as fork

    if (rc < 0) // if there is no fork
    {
        fprintf(stderr, "fork failed\n"); // prints fork failed error
        exit(1);
    }
    else if (rc == 0) // if child is true
    {
        printf("hello, I am child (pid: %d) and x is: %d\n", (int)getpid(), x); // prints pid of child
        x++;                                                                    // counts x up one
        printf("child again, x is now: %d\n", x);                               // prints the x count
    }
    else
    {
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int)getpid(), x); // prints parent pid
        x--;                                                                               // counts x down
        printf("parent again, x is now: %d\n", x);                                         // prints what x is currently
    }
    return 0; // because int main and not void main returns 0
}
