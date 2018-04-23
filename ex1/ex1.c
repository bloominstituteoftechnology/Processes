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
    int child = fork();

    if(child < 0) {
        perror("fork failed\n");
        exit(1);
    }
    else if (child == 0) {
        x++;
        printf("this is the child x: %d\n", x);
    } else {
        x--;
        printf("this is the parent x: %d\n", x);
    }

    return 0;
}
