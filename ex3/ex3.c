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
    int ex3_fork = fork();

    if (ex3_fork < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (ex3_fork == 0){ //child
        printf("hello!");
    } else { // parent
        wait(NULL);
        printf("goodbye!");
    }

    return 0;
}
