// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int value = 100;

    int rc = fork();

    if (rc == 0) {
        printf("c value: %d\n", value);
        value *= value - 5;
        printf("value after c change: %d\n", value);
        return 0;
    } else if (rc != 0) {
        printf("p value: %d\n", value);
        value += value - 12;
        printf("value after p change: %d\n", value);
        return 0;
    } else {
        printf("Error\n");
        return 1;
    };

    return 0;
}
