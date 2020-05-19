// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

    pid_t pid;        // _t means type delcaration pid under the hood it is an int.
    pid = fork(); // doesn't take paramters

    if (pid == 0) {
        printf("hello\n");
    } else {
        wait(NULL);     // to ensure that child runs first
        printf("goodbye\n");
    }
}
