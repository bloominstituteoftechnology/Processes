// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char string[30] = "This is just a test";
    int chameleon = 79;
    printf("%d\n", chameleon);
    printf("%s\n", string);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        int chameleon = 168;
        printf("%d\n", chameleon);
        // string = "This is not cool";
        // printf("I am a child of %s, my id is %d \n", string, (int) getpid());
    } else {
        int chameleon = 3;
        printf("%d\n", chameleon);
        // string = "I really am your...";
        // printf("%s\n", string);
        // printf("Luke... I am... %d\n", (int) getpid());
    }
    // Your code here

    return 0;
}
