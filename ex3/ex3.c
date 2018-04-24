// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
    // clone parent to a child
	int rc = fork();

	 if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //in child process
        printf("hello\n");
    } else {
        //in parent process
        //wait for child process to finish executing
    	int wc = waitpid(rc, NULL, 0);
        //print googbye
        printf("goodbye\n");
    }

    return 0;
}
