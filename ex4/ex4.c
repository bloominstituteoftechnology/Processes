// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// exec() replaces the current processe's program with another one that you specified. If a child process is not created
// and the parent calls an exec() then the current program will end since it gets replaced by a different program
// Anything after 'exec' such as l, v, p, and e, describes the behavior of the exec and what you can pass into
// exec() as arguments. execvpe, for example, can specify the environment which the process can run in. 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{

    pid_t pid = fork();

    if (pid == 0) {
        char *ls_process[] = {"/bin/ls", NULL};
        execvp(ls_process[0], ls_process);
        exit(1);
    }
    else {
        waitpid(pid, NULL, 0);
        puts("Parent will continue executing since child has finished");
        char *wc_process[3];
        wc_process[0] = "wc";
        wc_process[1] = "ex4.c";
        wc_process[2] = NULL;
        execvp(wc_process[0], wc_process);
    }
    return 0;
}
// https://stackoverflow.com/questions/4204915/please-explain-the-exec-function-and-its-family
// int execv(const char *path, char *const argv[]);
// int execvp (const char *file, char *const argv[]);
