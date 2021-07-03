// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // The variable value stays the same in the fork. If changed, the value will be unique to each instance.
    // Your code here
    int x = 100;
    int test = fork();
    if(test == 0) {
        printf("Child %i\n", x);
        x = 5;
        printf("Child%i\n", x);
    } else {
        printf("Parent %i\n", x);
        x = 10;
        printf("Parent%i\n", x);
    }
    return 0;
}
