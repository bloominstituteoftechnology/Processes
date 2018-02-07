// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here

printf("hey this is the last line before the fork.\n");
    // child process starts executing here
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
    
        printf("hello\n.");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Goodbye");
    }
    return 0;
}

