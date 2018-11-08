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
    if (fork() == 0)
    {
        printf("This is the child. Hello!\n");
    }
    else
    {
        wait(NULL);
        printf("This is the parent. Goodbye!\n");
    }

    return 0;
}
