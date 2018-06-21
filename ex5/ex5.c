// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

// This was helpful:  https://www.geeksforgeeks.org/pipe-system-call/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    // Just like in the pipe example from the lecture we are going to go and
    // define an inbuffer:
    char inbuf[MSGSIZE];
    // We are going to hold our read and write file descripters in p
    // nbytes stands for number of bytes.  Read returns the number of bytes
    // that were read, so if it is
    int p[2], nbytes;

    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(2);
    }
    if (rc == 0)
    {
        printf("Hi, child (pid: %d) here.  Writing messages to pipe...\n", getpid());
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        close(p[1]);
    }

    else
    {
        wait(NULL);
        close(p[1]); // closes the right end of the pipe here, as child is done writing by this point
        printf("Hi, parent of %d (pid: %d) here, reading and printing messages from pipe...\n", rc, getpid());
        while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
        { // can also use `for(int i = 0; i < 3; i++){}` BUT this is static looping (not practical)
            printf("%s\n", inbuf);
        }

        printf("Finished reading\n");
    }
    return 0;
}
