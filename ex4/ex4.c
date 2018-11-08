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
    pid_t pid = fork();

    if (pid == 0)
    {
        char *ls_process[] = {"/bin/ls", NULL};
        execvp(ls_process[0], ls_process);
        exit(1);
    }
    else
    {
        waitpid(pid, NULL, 0);
        puts("Since child has finished, parent will continue executing");
        char *wc_process[3];
        wc_process[0] = "wc";
        wc_process[1] = "ex4.c";
        wc_process[2] = NULL;
        execvp(wc_process[0], wc_process);
    }

    return 0;
}
