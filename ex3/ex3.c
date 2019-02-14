// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int child = fork();
    if (child < 0)
    {
        printf("\nFork failed\n");
    }
    else if (child == 0)
    {
        printf("\nhello\n");
    }
    else
    {
        int wc = waitpid(child, NULL, 0);
        printf("\ngoodbye\n");
    }

    return 0;
}
