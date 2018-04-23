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
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork Failed\n", x);
        exit(1);
    } else if (rc == 0) {
        printf("Child value before process = %d\n", x);
         
        x = 30;
        
        printf("value of Child after process = %d\n", x);
    } else {
        printf("Parent value before process = %d\n", x);

        x = 50;

        printf("Parent value after process = %d\n", x);
    }

    return 0;
}
