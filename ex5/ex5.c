// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16
//defines constant message size for each message

char *msg1 = "hello world #1\n";
char *msg2 = "hello world #2\n";
char *msg3 = "hello world #3\n";

int main(void)
{
    // Your code here

    char inbuf[MSGSIZE]; //buffer holds incoming data being written
    int p[2];            //two elemet array to hold read and write file descriptors used by pipe
    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    int pid = fork();

    if (pid == 0)
    {
        //child
        printf("Adding stuff to pipe in the child\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        //parent
        printf("welcome to the parent\n");
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%s", inbuf);
        }
        wait(NULL);
    }
    return 0;
}