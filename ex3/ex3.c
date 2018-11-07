// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int forked = fork();
    
    if (forked < 0) {   
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (forked == 0) {    
        printf("hello\n");
    } else {
        int wc = waitpid(forked, NULL, 00);   
        printf("goodbye");
    }
    return 0;
}
