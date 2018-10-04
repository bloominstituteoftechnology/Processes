// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello!\n");
    } else {
        int wc = waitpid(rc, NULL, 0); //wait for the process with PID = rc to complete
        // or we can do this, simpler version of essentially the same thing as above: wait(NULL);
        printf("Goodbye!\n");
    }
    return 0;
}