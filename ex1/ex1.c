// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
// well well well

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int f = fork();

    if(f < 0){
        printf("Fork failed!\n");
        exit(1);
    } else if(f == 0){
        x = 19;
        printf("Child value of x: %d\n", x);
    } else {
        printf("Parent value of x: %d\n", x);
        x = 42;
        printf("Parent value of x changed to: %d\n", x);
    }
    return 0;
}
