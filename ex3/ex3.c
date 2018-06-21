// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello \n");
    } else {
        // we ensure that the parent process only runs after the child process has finished its execution
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        printf("goodbye \n");
    }

    return 0;
}
