// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 15

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    // Your code here
    char inbuf[MSGSIZE];
    int p[2];
    int status;

    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int fk = fork();
    if (fk < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fk == 0)
    {
        printf("1. Child process pid: %d, start to write\n", (int)getpid());
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("2. Child process pid: %d, end of write\n", (int)getpid());
    }
    else
    {
        while (waitpid(fk, &status, WNOHANG) == 0)
        {
            sleep(1);
        }
        printf("3. Parent process pid: %d, start to read\n", (int)getpid());
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        printf("4. Parent process pid: %d, end of read\n", (int)getpid());
    }

    return 0;
}
