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
    int waitPID = waitpid(rc, NULL, 0);

    if (rc < 0) {
        fprintf(stderr, "Failure to fork\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child \t Hello \n");
    } else {
        printf("Parent \t Goodbye \n");
    }
    
    return 0;
}
