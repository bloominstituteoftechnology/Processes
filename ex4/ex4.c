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
    printf("hello world (pid: %d)\n", (int)getpid());
    int f = fork();
    if (f < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if (f == 0)
    {
        execl("/bin/ls", "ls", "-la", NULL);
        printf("you can't see me");
    }

    else
    {
        int wc = wait(NULL);
        printf("It's the parent (pid: %d) of child %d\n", (int)getpid(), f);
    }

    return 0;
}
