// Write another program using `fork()`.

// The child process should print "hello";
// The parent process should print "goodbye".

// You should ensure that the child process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        waitpid(rc, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
