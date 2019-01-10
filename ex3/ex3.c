// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int pcp = fork();

    if (pcp != 0) {
        printf("Hello from the Child\n");
    } else {
        printf("Goodbye from the Parent\n");
    }

    return 0;
}
