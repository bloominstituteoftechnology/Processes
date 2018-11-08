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

    if(rc < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child says hello first!\n");
    } else {
        waitpid(rc, NULL, 0);
        printf("Parent says goodbye last!\n");
    }

    return 0;
}
