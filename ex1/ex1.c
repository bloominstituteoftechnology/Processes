// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // initialize variable for pid
    int x = 100;
    // this print result prints first with the pid
    printf("hello world (pid: %d)\n", (int)getpid());

    int rc = fork();

    if(rc < 0) {
        // this is an error handling print statement
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // this line runs after line 31 in response to the digit being decreased
        printf("hello, I am child (pid: %d) and x is: %d\n", (int)getpid(), x);
        x++;
        // after increasing the digit it will now print the result
        printf("child again, x is now: %d\n", x);
    } else {
        // this block runs after line 14 its printing the parents pid
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int)getpid());
        x--;
        // after decreasing the digit it will now print the new result
        printf("parent again, x is now: %d\n", x);
    }
    // this completes the program
    return 0;
}
