// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int main(int argc, char* argv[])
{
    // Your code here
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc ==0) {
        printf("child process\n");
    } else {
        sleep(1000);
        printf("goodbye\n");
    }
    return 0;
}
