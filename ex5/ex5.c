// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16 // define a constant message size for each message

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE]; // a buffer that will hold the incoming data that is being written
    int p[2];            // a two-element array to hold the read and write file descriptors that are used by the pipe

    // establish the pipe, passing it the p array so that it gets populated by the read and write file descriptors
    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork(); // create a child process
    if (rc < 0)      // if fork failed print out a standard error message and exit
    {
        fprintf(stderr, "fork failed\n");
        exit(2);
    }

    else if (rc == 0) // represents child process
    {
        printf("child writing to pipe\n");

        // write 16 bytes of data to the write file descriptor
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }

    else // represents parent process
    {
        int wc = waitpid(rc, NULL, 0); // ensures that the parent process only runs after the child process has finished executing

        close(p[1]); // close the write end of the pipe
        printf("parent reading from pipe\n");

        // read 16 bytes of data from the read file descriptor
        while (read(p[0], inbuf, MSGSIZE) > 0) // will continue to read until it returns 0 to indicate end-of-file
        {
            printf("%s\n", inbuf);
        }

        printf("finished reading\n");
    }

    return 0; // needs to return an integer
}
