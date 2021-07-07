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
    int pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("I am inside child process\n");
        // execl("./np", NULL);
        execv("./np", NULL);
        exit(0);
    } else {
        printf("I am inside parent process\n");
        wait(NULL);
    }

    return 0;
}
