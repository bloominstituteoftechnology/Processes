// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x;
    x = 100;

    int rc = fork();

    if ( rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if ( rc == 0) {
        printf("child: %d\n", x); //value of x = 100 in child
        x = 200; //parent does not change value of child after fork
        printf("new chiled x:%d\n", x);

    }
    else {
        printf("parent: %d\n", x);
        x = 300; //child does not change the value of parent after fork
        printf("new parent x:%d\n", x);
    }


    return 0;
}
