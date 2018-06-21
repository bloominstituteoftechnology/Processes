// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    // Your code here

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr,"fork failure\n");
    }
    else if (rc == 0)
    {
        execl("/bin/ls", "ls", "-1", NULL);
    } else {
        wait(NULL);
    }

    return 0;
}