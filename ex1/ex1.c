// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int first = fork();
    printf("Hello world (x: %d)\n", x);

    if(first < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(first == 0) {
        printf("Hello, this is child (x: %d) \n", x);
        x = 12;
        printf("Hello, this is updated child (x: %d) \n",  x);
    }
    else {
        printf("Hello, this is parent (x: %d) of child %d\n", x, first);
        x = 45;
        printf("Hello, this is updated parent (x: %d) of child %d\n", x, first);
    }
    return 0;
}
