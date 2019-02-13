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
    int f = fork();
    if (f < 0)
    {
        printf("%s\n", "Fork faliled");
        exit(1);
    }
    else if (f == 0)
    {
        // we are in the child branch
        char *args[] = {"ls", "-a", NULL};
        // execvp(args[0], args);
        execvp(args[0], args);
    }
    else
    {
        // we are in the parent branch
        int wc = waitpid(f, NULL, 0);
        printf("%s\n", "Child finished, exiting program");
    }

    return 0;
}
