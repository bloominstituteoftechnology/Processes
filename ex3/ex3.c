// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(int argc, char* argv[])
{
    // Your code here

    char *h = "Hello";
    char *g = "Goodbye";

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "failed fork\n");
    }

    else if (rc == 0) {
        printf("Child: %s\n", h);
    }

    else {
        int wp = waitpid(rc, NULL, 0);
        printf("Parent: %s\n", g);
    }
    

    return 0;
}
