// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int n = fork();
    if (n == 0)
    {
        printf("Hello\n");
    }
    else if (n > 0)
    {
        waitpid(n, NULL, 0);
        printf("Goodye\n");
    }

    return 0;
}
