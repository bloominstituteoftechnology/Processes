// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int count = fork();
    if(count != 0) {
        printf("goodbye %d\n", count);
    }
    else {
        printf("hello %d\n", count);
    }

    return 0;
}
