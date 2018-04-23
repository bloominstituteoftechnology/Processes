// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // testing value sharing (or lack thereof) between parent and child
    int x = 26;
    fork();
    x++;
    printf("%d\n", x);

    // testing conditionals when fork is stored as an int
    // int test = fork();
    // if (test < 0){
    //     printf("fork failed");
    //     exit(1);
    // }
    // else if (test == 0){
    //     x = 17;
    //     printf("fork successful %d\n", x);
    // }
    // else {
    //     x = 30;
    //     printf("who knows what happened? %d\n", x);
    // }

    return 0;
}