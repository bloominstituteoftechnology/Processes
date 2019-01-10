// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if (rc == 0) {                      // Child process
        printf("Child: Hello\n");
    } else if (rc > 0) {                // Parent process
        int wc = waitpid(rc, NULL, 0);  // Wait for process with (pid == 0) to terminate
        printf("Parent: Goodbye\n");
    } 

    return 0;
}
