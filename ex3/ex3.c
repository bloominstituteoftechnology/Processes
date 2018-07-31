// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    if (fork() == 0) {
        // return child
        printf("Hello\n");
    } else {
        // return parent
        wait(NULL);
        printf("Goodbye\n");
    }

    return 0;
}
