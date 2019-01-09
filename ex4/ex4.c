// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// > there are a few different ways to execute files; probably some are more conventional for some languages or environments than others.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    fork();

    // char *environ = "environment key";

    char *args[2];
    args[0] = "ls";
    args[1] = NULL;

    execv("/bin/ls", args);


    return 0;
}
