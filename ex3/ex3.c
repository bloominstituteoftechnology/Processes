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
    printf("Lets Do this!\n");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed || it's all up to spoon now\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello: (pid: %d)\n", (int) getpid());        
    } else {
        int wc = waitpid(rc, NULL, 0); // --> YOU SHALL WAIT
        printf("goodbye (pid: %d)\n", (int) getpid());
    }

    return 0;
}


/*
    - Print result:

        > Lets Do this!
        > hello: (pid: 9639)
        > goodbye (pid: 9638)
*/