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
    int f = fork();

    if (f < 0) {
        fprintf(stderr, "Forking failed.\n");
        exit(1);
    } else if (f == 0) {
        printf("Hello, daddy!!!\n");
    } else {
        int daddy = waitpid(f, NULL, 0);
        printf("Hello and goodbye, kiddo!!!\n");
    }

    return 0;
}
