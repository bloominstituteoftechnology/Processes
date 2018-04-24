// Write a program that calls `fork()`. Before calling `fork()`, 
// have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 
// What value is the variable in the child process?
// What happens to the variable when both the child and parent 
// change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int child = fork();

    if (child < 0) {
        perror("Fork Failed\n");
        exit(1);
    }
    else if (child == 0) {
        printf("Child X(Should be 100): %d\n", x);
        x = 200;
        printf("Child X after reassignment(Should be 200): %d\n", x);
    }
    else {
        printf("Parent X(Should be 100): %d\n", x);
        x = 300;
        printf("Parent X after reassignment(Should be 300): %d\n", x);
    }

    return 0;
}
