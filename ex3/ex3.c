// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int ret_val = fork();

    if (ret_val < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (ret_val == 0)
    {
        printf("Hello!\n");
    }
    else
    {
        wait(NULL);
        printf("Goodbye!\n");
    }

    return 0;
}
