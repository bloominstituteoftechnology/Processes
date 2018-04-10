// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int child = fork();

    if(child < 0)
    {
        printf("Child cannot be forked\n");
    } else if(child == 0)
    {
        printf("hello\n");
    } else
    {
        int wait = waitpid(child, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
