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
    fprint("goodbye \n");

   int rc = fork();

    if(fork < 0 ) {
        //do nothing
        exit(1);
    } else if (rc == 0) {
        printf("hello \n");
    } else {
        int wc = waitpid(rc, NULL, 0); // wait pid call added
        printf("goodbye \n");
    }

    return 0;
}
