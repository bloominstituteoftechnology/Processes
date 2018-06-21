// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("Parent process.\n");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child process.\n");
        char *args[] = {"ls", "-1", NULL};
        execv("/bin/ls", args); //v requires you to provide the absolute path to the program
        //execvp("ls", args);
        //execl("/bin/ls", "ls", "-l", NULL);
        //execlp("ls", "ls", "-1", NULL); path/name of program/flag/NULL

    }
    else
    {
        wait(NULL);
    }

    return 0;
}
