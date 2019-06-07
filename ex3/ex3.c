// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // printf("goodbye (pid: %d)\n", (int)getpid());
    int rc = fork();

    // child process starts executing here
    if (rc == 0)
    {
        printf("Child: hello\n");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent: goodbye\n");
    }
    return 0;
}
