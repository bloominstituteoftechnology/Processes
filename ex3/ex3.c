// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    printf("Make sure the child runs FIRST!\n");
    int rc = fork();
    if (rc == 0) {
        printf("hello\n");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
