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
    // Your code here
    int f = fork();
    char inbuf[MSGSIZE];
    int p[2];
    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failde\n");
        exit(1);
    }
    if (f < 0)
    {
        printf("%s\n", "Fork faliled");
        exit(1);
    }
    else if (f == 0)
    {
        // we are in the child branch
        close(p[0]); // close the read branch
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        close(p[1]); // close the write branch
    }
    else
    {
        // we are in the parent branch
        close(p[1]); // close the write branch
        wait(NULL);
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        close(p[0]); // close the read branch
    }
    return 0;
}
