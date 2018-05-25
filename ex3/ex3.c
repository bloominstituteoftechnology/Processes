// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int lf = fork();

    if (lf < 0)
    {
        printf(stderr, "FATAL ERROR\n");
        exit(1);
    }
    else if (lf == 0)
    {
        printf("Hello (pid: %d)\n", (int)getpid());
    }
    else
    {
        waitpid(lf, NULL, 0);
        printf("Goodbye (pid: %d)\n", (int)getpid(), lf);
    }

    return 0;
}
