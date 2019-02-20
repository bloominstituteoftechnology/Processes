// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

    int child = fork();

    if(child) {
        printf("Hello");
    } else {
        wait(NULL);
        printf("Goodbye");
    }

    return 0;
}
