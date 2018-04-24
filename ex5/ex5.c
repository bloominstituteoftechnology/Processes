// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    char buffer[MSGSIZE];
    int p[2];

    if (pipe(p) < 0)
    {
        perror("Pipe Failed\n");
        exit(1);
    }

    int child = fork();

    if (child < 0)
    {
        perror("Fork Failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        int wc = waitpid(child, NULL, 0);
        for (int i = 0; i < 3; i++)
        {
            read(p[0], buffer, MSGSIZE);
            printf("%s\n", buffer);
        }
    }

    return 0;
}
