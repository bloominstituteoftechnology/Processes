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
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("hello, child here (pid: %d) \n", (int) getpid());
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }
    return 0;
}
