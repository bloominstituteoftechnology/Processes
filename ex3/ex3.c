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

    if (f > 0) {
        //waitpid() makes the process go second
        //since parent has waitpid() it should go after child
        int w = waitpid(f, NULL, 0);
        printf("Parent says goodbye.\n");
    }
    else if (f == 0)
    {
        printf("Child says hello!\n");
    }
    else
    {
        fprintf(stderr, "Fork Failed!\n");
        exit(1);
    }

    return 0;
}
