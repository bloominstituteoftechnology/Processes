// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // char hello = "hello";
    int f = fork();
    if (f < 0) {
        fprintf(stderr, "fork failed\n");
    }
    else if (f == 0) {
        // hello = "goodbye";
        // printf("child: %s\n", hello);
        printf("hello\n");
    }
    else {
        // printf("parent: %s\n", hello);
        int wc = wait(0);
        printf("goodbye\n");
    }

    return 0;
}
