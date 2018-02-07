// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int status;
    int pid = fork();
    // printf("pid: %d\n", pid);
    // printf("status: %d\n", status);
    if (pid == 0)
    {
        printf("hello\n");
    }
    else
    {
        pid = wait(&status);
        // printf("pid: %d\n", pid);
        // printf("status: %d\n", status);
        printf("goodbye\n");
    }

    return 0;
}
