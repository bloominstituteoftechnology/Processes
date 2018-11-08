// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    int rc = fork();

    if (rc == 0) // Child
    {
        printf("Child: pid %d\n", (int)getpid());
        execl("/bin/ls", "ls", "-l", (char *)NULL);
    }

    else if (rc > 0) // Parent
    {
        wait(NULL);
    }

    else
    {
        fprintf(stderr, "Error Occurred During Fork()");
    }

    return 0;
}
