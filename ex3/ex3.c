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
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failure\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
        printf("child (pid: %d) print before parent - pls work\n", (int) getpid());
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("goodbye\n");
        printf("parent (pid: %d) and the child (pid: %d)", (int) getpid(), rc);
    }
    
    return 0;
}
