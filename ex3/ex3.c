// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Parent pid %d \n", getpid());
    int rc = fork();
    if (rc == 0)
    {
        printf("Child pid %d saying hello \n", getpid());
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent pid %d saying goodbye\n", getpid());
    }
    return 0;
}