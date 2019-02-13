// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int child_process = fork();
    if (child_process < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (child_process == 0)
    {
        printf("hello.\n");
    }
    else
    {
        int wc = waitpid(child_process, NULL, 0);
        printf("goodbye.\n");
    }
    return 0;
}
