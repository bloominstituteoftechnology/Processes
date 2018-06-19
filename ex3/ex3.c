// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    int status; // status of process
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0) {
        printf("child: hello\n");
    }
    else {

        while(waitpid(rc, &status, WNOHANG) == 0) {
            sleep(1);
        }
        printf("parent: goodbye\n");
    }

    return 0;
}
