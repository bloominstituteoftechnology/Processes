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
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        int wc = waitpid(rc, NULL, WUNTRACED | WCONTINUED);
        // pid_t waitpid(pid_t rc, int *status_ptr, int options);
        printf("goodbye\n");
    }
    return 0;
}
