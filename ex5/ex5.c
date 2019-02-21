// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    char inbuff[MSGSIZE];
    int p[2];

    if (pipe(p) < 0)
    {
        printf("Pipe failed\n");
        exit(1);
    }

    printf("pre-fork: pid %d\n", (int)getpid());

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("post-fork: child pid %d\n", (int)getpid());

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("post-fork: parent pid %d of child %d\n", (int)getpid(), rc);

        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuff, MSGSIZE);

            printf("% s\n", inbuff);
        }
    }

    return 0;
}
