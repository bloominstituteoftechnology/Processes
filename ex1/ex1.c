// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    // the parent and the child will have their own copy. the parent going down, the child going up.
    if (rc < 0) {
        // stderr = standard error (like error response specified in server calls (.catch))
        // fprinf is common with stderr, since printf is defualted to stdout = standard output
        fprintf(stderr, "fork failed...\n");
        exit(1);
    } else if (rc == 0) {
        // pid = process id number..(int) is to be explicit about getting an integ. (look up: pid_t)
        printf("I'm the child! (pid: %d) and x is : %d.\n", (int) getpid(), x);
        x++;
        printf("Child again... x is now: %d\n", x);
    } else {
        printf("I'm the parent! (pid: %d) and x is : %d.\n", (int) getpid(), x);
        x--;
        printf("Parent again... x is now: %d\n", x);
    }

    return 0;
}
