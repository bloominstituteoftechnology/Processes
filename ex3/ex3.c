// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Before forking pid: %d\n", (int)getpid());
    int rc = fork();
    //fork failed
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    //child process
    else if (rc == 0)
    {
        printf("Child: Hello pid: %d\n", (int)getpid());
    }
    else
    {
        //wait for child to complete
        waitpid(rc, NULL, 0);
        printf("Parent: Goodbye pid: %d\n", (int)getpid());
    }

    return 0;
}
