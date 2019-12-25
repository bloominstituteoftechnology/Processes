// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 5;
    printf("cool x = %d\n", x);
    int child = fork();
    if (fork() == 0){
    x = 6;
    printf("child wants x to = %d\n", x);
    } else {
    x = 7;
    printf("parent wants x to = %d\n", x);
    }
    printf("so now x = %d\n\n", x);
    return 0;
}
