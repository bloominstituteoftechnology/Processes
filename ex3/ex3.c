// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // assign the fork to rc
    int rc = fork();

    if (rc < 0) 
    {
        // format print a standard error
        fprintf(stderr, "fork failed\n");
        // exit the block
        exit(1);
    }
    else if (rc == 0)
    {
        // if it's the child process, print Hello!
        printf("Hello!\n");
    }
    else
    {
        // if it is the parent, it uses waitpid, then prints Goodbye
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        printf("Goodbye!\n");
    }
    return 0;
}
