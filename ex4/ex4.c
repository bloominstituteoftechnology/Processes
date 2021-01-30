// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int responseFromFork = fork();
    if (responseFromFork < 0) {
        fprintf(stderr, "You forked up!\n");
        exit(1);
    } else if (responseFromFork != 0) {
        printf("Other fork is executing ls\n");
    } else {
        execvp("/bin/ls", argv);
    }

    return 0;
}
