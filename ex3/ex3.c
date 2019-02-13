// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fp = fork();
    if (fp < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fp == 0)
    { // child process satisfies this branch
        printf("hello\n");
    }
    else
    {
        int wc = waitpid(fp, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
