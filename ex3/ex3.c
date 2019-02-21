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

    if (rc < 0)
    {
        printf(stderr, "Forking failed \n");
    }
    else if (rc == 0)
    {

        printf("Hello there, if rc==0, this is our child processID is: (pid: %d) \n", (int)getpid());
        printf("Goodbye\n");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Hello there, if rc==0, this is our Parent processID is: (pid: %d) \n", (int)getpid());
        printf("Hello\n");
    }

    return 0;
}