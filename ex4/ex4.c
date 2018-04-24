// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    int chfork = fork();

    if (chfork < 0)
    {

        fprintf(stderr, "Fork Unsuccessful.\n");
        exit(1);
    }
    else if (chfork == 0)
    {
        execvp("/bin/ls", argv);
    }

    return 0;
}
