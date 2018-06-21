// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

/* pipe is uni-directional, i.e. one way.
One end for granting write access, other end for granting read access.

two-directional read and write would require two pipes.
write to a pipe in FIFO order.


*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    char buffer[MSGSIZE];

    int p[2];

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child here\n");

        if (pipe(p) < 0)
        {
            fprintf(stderr, "pipe failed\n");
            exit(1);
        }

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        printf("Parent here\n");
        for (int i = 0; i < 3; i++)
        {
            read(p[0], buffer, MSGSIZE);
            printf("% s\n", inbuf);
        }
    }
    return 0;
}
