// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int ret = fork();

    if (ret < 0) {
        fprintf(stderr, "Failed to Fork");
        exit(1);
    }
    else if (ret == 0) {
        printf("hello\n");
        printf("Child (pid: %d)\n\n", (int) getpid());
    }
    else {
        int wc = waitpid(ret, NULL, 0); //Is this all I need to do?
        printf("goodbye\n\n");
        printf("Parent (pid: %d) \nAND\nChild (pid: %d)\n", (int) getpid(), ret);
    }

    return 0;
}
