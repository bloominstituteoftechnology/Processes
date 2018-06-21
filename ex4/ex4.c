// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here
    const int RC = fork();
    if (RC < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (RC == 0) {
        execlp("ls", "ls", "-l", NULL);
    }
    else {
        int wc = waitpid(RC, NULL, 0);
        printf("Parent process finished.\n");
    }
    return 0;
}
