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
    int child_process = fork();
    if (child_process < 0)
    {
        fprintf(stderr, "Failure to fork!\n");
        exit(1);
    } 
    else if (child_process == 0)
    {
        // char *argv[] = {"ls", NULL};
        // execvp("/bin/ls", argv);
        execl("/bin/ls", "ls", (char *)0);
    }
    else
    {
        int wc = waitpid(child_process, NULL, 0);
    }
    return 0;
}
