// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int a = 100;
    printf("I'm the parent (pid: %d)\n", (int) getpid());
    int b = fork();
    if (b < 0) {
        fprintf(stderr, "What the fork!!\n");
        exit(1);
    } else if (b == 0) {
        printf("I'm the child (pid: %d) and a is: %d\n", (int) getpid(), a);
        a++;
        printf("I'm a little child and a is now: %d\n", a);
    } else {
        printf("I'm the parent of %d (pid: %d) and a is: %d\n", b, (int) getpid(), a);
        a--;
        printf("I'm the parent!!!, a is: %d\n", a);
    } 
    
    return 0;
}
