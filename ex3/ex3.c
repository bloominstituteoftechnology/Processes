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
    int rv = fork();
    wait(0);
    if(rv < 0){
        printf("fork failed");
    }else if(rv == 0){
        printf("hello\n");
        exit(1);
    }
    printf("goodbye\n");
    return 0;
}
