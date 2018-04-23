// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    int new_fork = fork();

    if (new_fork < 0 ) {
        printf("Fork failed!\n");
    } else if (new_fork == 0) {
        printf("This is the child with PID is %d\n", getpid());
        printf("Here is x in child: %d\n", x);
        x = 95;
        printf("Here is x in child after assigning to 95: %d\n", x);
    } else {
        printf("This is the parent with PID: %d\n", getpid());
        printf("Here is x in the parent: %d\n", x);
        x = 70;
        printf("Here is x in the parent after assign to 70: %d\n", x);
    }

    return 0;
}
