// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    int forky_fork = fork();

    if (forky_fork < 0)
    {
        printf("The world may have ended, because something has gone wrong.");
    }
    else if (forky_fork == 0)
    {
        printf("Hello, Dave!\n");
    }
    else
    {
        waitpid(forky_fork, NULL, 0);
        printf("...goodbye, Dave.\n %10s\n", ":(");
    }
    return 0;
}
