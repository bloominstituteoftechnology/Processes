// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello\n");
    } else {
        while (waitpid(rc, &status, WNOHANG) == 0) {
            sleep(1);
        }
        printf("Goodbye\n");
    }

    return 0;
}
