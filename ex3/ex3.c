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
    int forked = fork();
    if (forked < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (forked == 0){
        puts("hello");
    } else {
        waitpid(forked, NULL, 0);
        puts("goodbye");
    }
    return 0;
}
