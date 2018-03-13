// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t FPID = fork();

    if (FPID != 0)
    {
        wait(NULL);
        printf("Parent complete.");
    }
    if (FPID == 0)
    {
        execl("/bin/ls", "ls", "-la", NULL);
    }

    return 0;
}

// complete with a child call