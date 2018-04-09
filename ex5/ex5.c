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

int main()
{
    int p_parent[2];
    int p_child[2];

    if (pipe(p_child) < 0 || pipe(p_parent) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    /* set parent read pipe to child read pipe */
    p_parent[0] = p_child[0];
    close(p_parent[1]); /* close parent write pipe */

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork() failed\n");
    }

    else if (rc == 0)
    {
        close(p_parent[0]); /* close parent write pipe */

        write(p_child[1], msg1, MSGSIZE);
        write(p_child[1], msg2, MSGSIZE);
        write(p_child[1], msg3, MSGSIZE);

        close(p_child[1]); /* close child write pipe */
    }

    else
    {
        int wc = waitpid(rc, NULL, 0);
        char inbuf[MSGSIZE];

        for (int i = 0; i < 3; i++)
        {
            read(p_parent[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }

    return 0;
}
