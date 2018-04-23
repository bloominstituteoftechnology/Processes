// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int val = 100;
    int postF = fork();
    if (postF < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (postF == 0) {
        val += 5;
        printf("child val is %i\n", val);
    } else {
        val += 10;
        printf("parent val is %i\n", val);
    }
    
    return 0;
}
