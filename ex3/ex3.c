// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int child = fork();

    if (child < 0) {   
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (child == 0) {  
        printf("Hello from the child\n");
    } else {
        waitpid(child, NULL, 0);
        printf("Goodbye from the parent\n");
    }

    return 0;
}