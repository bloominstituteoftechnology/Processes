// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int childProcess = fork();

    if (childProcess < 0) {
        printf("fork failed\n");
    } else if (childProcess == 0) {
        printf("hello\n");
    } else {
        int wc = waitpid(childProcess, NULL, 0);
        printf("goodbye\n");
    }
    return 0;
}
