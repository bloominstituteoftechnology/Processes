// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
   
    printf("File descriptor: %d\n");

    int rc = fork();

    if (rc < 0) {
        printf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello from child\n");
    } else {
        int wc = waitpid(rc, NULL, 0); // rc (i.e. fork()) returns the pid of the child
        printf("goodbye from parent\n");
    }

    return 0;
}
