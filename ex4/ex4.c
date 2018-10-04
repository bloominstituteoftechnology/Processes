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
    int ret_val = fork();

    if (ret_val < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (ret_val == 0)
    {
        char *args[] = {"./bin/ls", NULL};
        execvp(args[0], args);  //execvp
        printf("Child process?\n");

    } else if (ret_val > 0)
    {
       wait(NULL);
       printf("Parent\n");
    }
    return 0;
}
