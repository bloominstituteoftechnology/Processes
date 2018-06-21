// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(int argc, char *argv[])
{

    printf(" process id: %d \n", (int)getpid());
    /////////////////////////////////////
    int myPipe[2];
    int ret;
    char inBuf[MSGSIZE];
    ret = pipe(myPipe);

    if (ret == -1)
    {
        perror("pipe");
        exit(1);
    }

    ///////////////////////////////////////////
    int rc = fork();
    printf("*****(rc:%d) \n", rc);
    /////////////////////////////////////////////// ===> child starts here
    if (rc < 0)
    {
        fprintf(stderr, " fork failed \n");

        exit(1);
    }
    else if (rc == 0)
    {

        printf("=======> child here (pid:%d)\n", (int)getpid());

        write(myPipe[1], msg1, MSGSIZE);
        write(myPipe[1], msg2, MSGSIZE);
        write(myPipe[1], msg3, MSGSIZE);
    }
    else
    {

        printf("========>parent here (pid: %d)  of child  (rc:%d)\n", (int)getpid(), rc);
        for (int i = 0; i < 3; i++)
        {
            read(myPipe[0], inBuf, MSGSIZE);
            printf(" %s \n", inBuf);
        }
    }

    return 0;
}
