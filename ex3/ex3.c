// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int f = fork();
    if (f < 0)
    {
        printf("%s\n", "Fork faliled");
        exit(1);
    }
    else if (f == 0)
    {
        // we are in the child branch
        printf("%s\n", "hello");
    }
    else
    {
        // we are in the parent branch
        wait(NULL);
        printf("%s\n", "goodbye");
    }

    return 0;
}
