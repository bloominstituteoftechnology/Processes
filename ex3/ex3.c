// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf(" getpid is %d \n", (int)getpid());
    /////////////////////
    int rc = fork();
    printf("*****(rc:%d) \n", rc);
    ////////////////////////////////
    if (rc < 0)
    {
        fprintf(stderr, " fork failed \n");

        exit(1);
    }
    else if (rc == 0)
    {

        printf("=======> child here (pid:%d)\n", (int)getpid());
        printf("hello \n");
        //sleep(5);
        exit(0);
    }
    else
    {

        printf("========>parent here (pid: %d)  of child  (rc:%d)\n", (int)getpid(), rc);
        wait(NULL);
        printf("goodbay \n");
    }

    return 0;
}
