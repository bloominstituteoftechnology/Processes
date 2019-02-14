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
    int child = fork();

    if (child < 0)
    {
        printf("\nFork failed\n");
    }
    else if (child == 0)
    {
        char *args[2];
        args[0] = "/bin/ls"; // list files and dirs
        args[1] = NULL;

        execvp(args[0], args);
        printf("\nCan't be seen\n");
    }
    else
    {
        int wc = waitpid(child, NULL, 0);
        printf("\nParent\n");
    }

    return 0;
}
