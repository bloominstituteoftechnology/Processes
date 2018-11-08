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
    // Your code here
    int child = fork();
    if (child < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        execl("/bin/ls", "ls", "-l", (char *)NULL);
    }
    else
    {
    }
    return 0;
}

// There are many variants of the same basic call because they take in
// different types of arguments to accomodate different situations