// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int y = fork();
    if (y==0) {
        printf("hello\n");
        exit(0);
    } else {
        wait();
        printf("goodbye\n");
    }
    return 0;
}
