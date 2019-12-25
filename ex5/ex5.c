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
    //Your code here
    char inbuf[MSGSIZE];
    int fd[2];
    int p = pipe(fd);
    int rc = fork();
    if (p < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if (rc==0){
        printf("Child process sends 3 messages.\n");
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);

    } else {
        for (int i=0; i<3; i++) {
            read(fd[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        
    }

    return 0;
}
