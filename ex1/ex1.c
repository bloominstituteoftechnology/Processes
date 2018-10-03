// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("hello world (pid: %d)\n", (int) getpid()); // Set initial X value, print PID

    int rc = fork();  // Set rc to fork()

    if (rc < 0) {
        fprintf(stderr, "fork failed\n"); // If fork returns negative #, error
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d) and x is: %d\n", (int) getpid(), x); // If fork returns 0, we are inside the child function, print current status 
        x++; // Then increment X by 1
        printf("child again, x is now: %d\n", x); // Then print new status/X value
    } else {
        printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int) getpid(), x); // If fork returns a positive value, we are in a parent function, print current status
        x--; // Decrement X by 1
        printf("parent again, x is now: %d\n", x); // Print new status/X value
    }

    return 0;
}

