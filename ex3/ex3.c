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
    int rc = fork();
    //fork failed, then exit here w message.
    if (rc < 0){
        fprintf(stderr, "fork has failed\n");
        exit(1);
    }
    //child prints first with hello
    else if (rc == 0){
        printf("hello\n");
    }
    //added wait(NULL) to make sure child process prints first. Parent prints with goodbye.
    else {
        wait(NULL);
        printf("goodbye\n");
    }

    return 0;
}
