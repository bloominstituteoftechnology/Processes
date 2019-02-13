// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();

    if (rc < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    if (rc == 0)
    {
        printf("hello\n");
    }
    if (rc > 0)
    {
        waitpid(rc, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
