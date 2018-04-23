// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//int main(int argc, char* argv[])
int main()
{
    // Your code here
    int status;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Failed to fork, exiting\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        while (waitpid(rc, &status, WUNTRACED) == 0) {
            sleep(1);
        }
        printf("goodbye\n");
    }
    return 0;
}
