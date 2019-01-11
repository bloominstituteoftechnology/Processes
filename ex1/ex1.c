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

    printf("INITIAL value of x: %d\n", x);

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork did not succeed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d) and x is: %d\n", (int) getpid(), x);
        x = 101;
        printf("CHILD value of x: %d\n", x);
        //run something on child process
    } else {
        //run something on parent process
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int) getpid(), x);
        x = 102;
        printf("PARENT value of x: %d\n", x);

    }
    printf("LAST value of x - pid: %d - %d\n", x, (int) getpid());

    return 0;
}
