// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int ret = fork();
    // printf("Starting value of x should be 100\n %d", x);
    if (ret < 0) {
        fprintf(stderr, "Child Process Failed \n");
        exit(1);
    }
    else if ( ret == 0) {
        printf("Child Process Successful-- should be 50 \n");
        x = 50;
        printf("x = %d\n", x);
    }
    else {
        printf("Parent Process Here should be 25 \n");
        x = 25;
        printf("x = %d\n", x);
    }

    printf("I believe this is the main process again x =%d\n", x);

    return 0;
}
