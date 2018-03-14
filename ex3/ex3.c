// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
    int f = fork();
    if (f < 0)
        printf("something bad happened");
    else if (f == 0)
        printf("Hello\n");
    else
    {
        sleep(1);
        printf("Goodbye\n");
    }
    return 0;
}
