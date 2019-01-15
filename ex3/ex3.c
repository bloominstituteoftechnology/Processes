// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    // error handling
    if (rc < 0) {
        fprintf(stderr, "fork FAILED!!!\n");
        exit(1);
    } else if (rc ==0) {
        printf("Hello!\n");
    } else {
        // WNOHANG: will not suspend execution of the calling thread if status is not immediately available for one 
        // of the child processes specified by pid.
        // int wc = waitpid(rc, NULL, WNOHANG); //but this was printing out in the wrong order..so
        // (rc=child, NULL=status pointer, WNOHANG=status handling )
        int wc = waitpid(rc, NULL, 0);
        // printing childs exit status
        printf("child's pid: %d\n", wc);
        printf("Random Closer....!\n");
    }

    return 0;
}
