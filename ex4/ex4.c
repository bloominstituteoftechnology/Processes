// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// ANSWER:

// RANDOM LINK: https://stackoverflow.com/questions/12596839/how-to-call-execl-in-c-with-the-proper-arguments

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child process\n");
        char *args[] = {"ls",
                        "-l",
                        NULL};
        execvp("ls", args);
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("Waiting parent\n");
    }

    return 0;
}
