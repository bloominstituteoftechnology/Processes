// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ERROR_FORK[] = "System failed to execute fork()!";

int main(int argc, char *argv[])
{
    // Your code here
    char h[] = "Hello!";
    char g[] = "Goodbye..";
    int f = fork();

    if (f < 0)
    {
        printf("%s", ERROR_FORK);
    }
    else if (f == 0)
    {
        printf("%s", h);
    }
    else
    {
        int wc = waitpid(f, NULL, 0);
        printf("%s", g);
    }

    return 0;
}
