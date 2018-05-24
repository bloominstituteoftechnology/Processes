// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // waitip need to be includes seperately

int main(int argc, char* argv[])
{
    // Your code here
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();

    // child process starts
    if(rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0) {
        // child process satisfies this branch
        printf("Hello! Child here (pid: %d) \n", (int) getpid());
    }else{
        int wc = waitpid(rc, NULL, 0); // waitpid call added here
        printf("Goodbye!, parent here (pid: %d) of child %d\n", getpid(), rc);
    }

    return 0;
}
