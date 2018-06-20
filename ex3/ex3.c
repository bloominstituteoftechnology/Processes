// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(fork() == 0) {
        printf("Hello\n");
    }else {
        wait(NULL);
        printf("Goodbye\n";)
    }

    return 0;
}
