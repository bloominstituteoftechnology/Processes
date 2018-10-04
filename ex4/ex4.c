// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    // forking here!
    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = NULL;
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }
    else
    {
        waitpid(rc, NULL, 0);
    }
    return 0;
}
