// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE];
    int p[2];

    pipe(p);
    int rc = fork();

    if(rc == 0) // child /successful fork
    {
        printf("child writing to fork\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else if(rc > 0) // parent?
    {
        int waitcall = waitpid(rc, NULL, 0);
        printf("parent reading from child\n");
        // close(p[1]);
        for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        printf("parent is finished\n");
    }
    else if (pipe(p) < 0)
    {
        printf(stderr, "pipe failed\n");
        exit(2);
    }
    else if(rc < 0) // no fork
    {
        printf(stderr, "fork failed\n");
        exit(1);
    }
    return 0;
}
