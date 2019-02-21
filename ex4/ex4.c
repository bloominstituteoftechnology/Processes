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
    int fp = fork();
    if (fp < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fp == 0)
    { // child process satisfies this branch
        char *args[] = {"ls", "-a", NULL};
        // execvp(args[0], args);
        execvp(args[0], args);
    }
    else
    {
        //call exec on '/bin/ls
        int wc = waitpid(fp, NULL, 0);
        printf("Child process is complete");
    }

    return 0;
}
