// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    int x;
    x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed
        return 1;
    } else if (rc == 0) {
        printf("child here\n");
        x = 250;
        printf("x is %d\n", x);
    } else {
        printf("parent here\n");
        x = 1;
        printf("x is %d\n", x);
    }

    return 0;
}
