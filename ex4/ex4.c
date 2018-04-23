// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int responseFromFork = fork();
    if (responseFromFork < 0) {
        fprintf(stderr, "You forked up!\n");
        exit(1);
    } else if (responseFromFork != 0) {
        printf("I'm the parent fork");
    } else {
        printf("I'm the child fork");
        execl("/bin/ls", ".");
    }

    return 0;
}
