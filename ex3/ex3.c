// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rv = fork();

    if(rv < 0)
    {
        printf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rv == 0)
    {
        printf("hello\n");
    }
    else
    {
        int wc = waitpid(rv, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
