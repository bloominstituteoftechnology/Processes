// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // `waitpid` needs to be included separately

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process
        printf("Hello (pid: %d) %d \n", (int)getpid(), rc);
    }
    else
    { // parent process
        int wc = waitpid(rc, NULL, 0); // to wait for the child process to finish
        printf("Goodbye (pid: %d) %d\n", (int)getpid(), rc);
    }

    return 0;
}
