// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

// transform child process to hello
// execute parent process of goodbye after

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // child process hello
    char *child = 'Hello';
    // parent process goodbye
    char *parent = 'Goodbye';
    

    int rc = fork()
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if ( rc == 0) {
        printf("Child Process: %s\n", child);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf('Parent Process: $s\n', parent);
    }

    return 0;
}


