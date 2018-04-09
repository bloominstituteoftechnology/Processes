// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Process failed.\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello!\n");
    } else {
        int tc = waitpid(rc, NULL);
        printf("Goodbye!\n");
    }

    return 0;
}
