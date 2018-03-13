// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
    int forked = fork();
    if(forked == 0){  // child process
         printf("hello\n");
    } else{
        waitpid(forked, NULL, 0); // wait until the child process finishes
        printf("goodbye\n");
    }

    return 0;
}
