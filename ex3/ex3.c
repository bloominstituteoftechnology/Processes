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

    int fk = fork();
    if (fk < 0)
    {
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if (fk == 0)
    {
        printf("1. Chld process: %d, Hello\n", (int)getpid());
    }
    else
    {
        while (waitpid(fk, &status, WNOHANG) == 0)
        {
            sleep(1);
        }
        printf("2. Parent process: %d, Good-bye\n", (int)getpid());
    }

    return 0;
}
