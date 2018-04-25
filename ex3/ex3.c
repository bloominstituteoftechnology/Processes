// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
      int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello!\n");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Goodbye!\n");
    }
    return 0;
}
