// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16 // defining a constant size for each message

// char pointers to string arrays to be sent
char* msg1 = "hello world #1"; 
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    char inbuf[MSGSIZE]; // buffer to hold incoming data being written
    int p[2]; // two-element array to hold read/write file descriptors

    printf("%d is the current process running\n", (int) getpid());
// establish the pipe
// print an error to stderr if failure
    if (pipe(p) < 0)
    {
        fprintf(stderr, "Pipe failure!\n");
        exit(1);
    }
    else
    {
        int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("%d is the process running before writing\n", (int) getpid());
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("%d is the process running after writing\n", (int) getpid());
    }
    else
    {
        waitpid(rc, NULL, 0);
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%d prints out the message %s\n", (int) getpid(), inbuf);
        }
    }
    }

    
    return 0;
}
