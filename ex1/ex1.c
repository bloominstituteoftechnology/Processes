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

    printf("What up??!! (pid: %d, x: %d)\n", (int) getpid(), x);
    
    int f = fork();

    if (f < 0) {
        fprintf(stderr, "forking failed :(\n");
        exit(1);
    } else if (f == 0) {
        printf("Hi there!!!!! What up??? Kiddo is speaking here (pid: %d, x: %d)\n", (int) getpid(), x + 5);
    } else {
        printf("Hi. Ths is parent (pid: %d, x: %d) of child (pid: %d, x: %d)\n", (int) getpid(), x, f, x + 1);
    }

    return 0;
}
