// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//int main(int argc, char *argv[])
int main()
{
    // Your code here
    int x = 100;
    
    printf("Parent x value: %d\n", x);
    int rc = fork();
    x = 201;
    
    if (rc < 0) {
        fprintf(stderr, "Fork failed, exiting.\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child x value: %d\n", x);
    } else {
        x = 9000;
        printf("New parent x value: %d\n", x);
    }
    return 0;
}

// Parent x value: 100
// New parent x value: 9000
// Child x value: 201
