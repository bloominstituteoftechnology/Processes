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
    int fk = fork();
    if (fk < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (fk == 0)
    {
        printf("1. Child process pid: %d\n", (int)getpid());
        char *path = "/bin/ls";
        char *arg_list[] = {"ls", "-l", NULL};
        char *env_list[] = {"HOME=/Users/ting", NULL};
        execl(path, arg_list[0], arg_list[1], arg_list[2]);
        execle(path, arg_list[0], arg_list[1], arg_list[2], env_list);
        execv(path, arg_list);
    }
    else
    {
        wait(NULL);
    }
    return 0;
}
