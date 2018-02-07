// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    // Your code here
    int fd[2];
    char readbuffer[80];
    pipe(fd);
    int pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        write(fd[1], msg1, MSGSIZE);
        // write(fd[1], msg1, (strlen(msg1) + 1));
        // exit(0);
    }
    else
    {
        close(fd[1]);
        read(fd[0], readbuffer, MSGSIZE);
        // read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Received string: %s\n", readbuffer);
    }

    return 0;
}
