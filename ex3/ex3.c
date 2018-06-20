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
    if(rc < 0) {
        fprintf(stderr, "Fork was not successful, exiting program.\n");
    } else if(rc == 0) {
        printf("Hello!\n");

    } else {
        sleep(1);
        printf("Goodbye!\n");
    }
    return 0;
}
