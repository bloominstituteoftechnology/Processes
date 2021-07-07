// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // system call to create new child process
    int rc = fork();

    // checking if less than
    if (rc < 0) {
        // printing error results
        fprintf(stderr, "fork failed\n");
        // exit status of failure
        exit(1);
        // checking if equal to
    } else if (rc == 0) {
        printf("Hello!\n");
    } else {
        // wait for process to end function
        int wc = waitpid(rc, NULL, 0);
        printf("Goodbye!\n");
    }
    // program completion
    return 0;
}
