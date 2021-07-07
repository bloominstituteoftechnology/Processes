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
    printf("Initial Process (pid: %d)\n", (int) getpid());

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Hello. Child Process (pid: %d)\n", (int) getpid()); 
    }
    else
    {
        // The wait() system call 
        // (along with the more complete waitpid() system call) 
        // allows us to get around this non-determinism if that is something 
        // that needs to be accounted for. In this case, we want the child prints first.
        int wc = waitpid(rc, NULL, 0);
        printf("Goodbye. Parent Process (pid: %d)\n", (int) getpid());
    }

    return 0;
}
