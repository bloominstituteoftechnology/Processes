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

int main()
{
    // int p[2];            // a two-element array to hold the read/write file descriptors used by the pipe
    // char inbuf[MSGSIZE]; // a buffer to hold the incoming data being written

    // // establish the pipe, passing it the p array so that it gets populated by the read and write file descriptors
    // if (pipe(p) < 0)
    // {
    //     fprintf(stderr, "pipe failed\n");
    //     exit(1);
    // }
    // int rc = fork();

    // // write 16 bytes of data to the write file descriptor
    // if (rc < 0)
    // {
    //     printf(stderr, "fork failed!\n");
    //     exit(2);
    // }
    // else if (rc == 0)
    // {
    //     printf("child writing to pipe\n");
    //     write(p[1], msg1, MSGSIZE);
    //     write(p[1], msg2, MSGSIZE);
    //     write(p[1], msg3, MSGSIZE);
    // }
    // else
    // {
    //     int wc = waitpid(rc, NULL, 0);
    //     close(p[1]);
    //     printf("parent reading from pipe\n");

    //     while (read(p[0], inbuf, MSGSIZE) > 0)
    //     {
    //         // read 16 bytes of data from the read file descriptor
    //         read(p[0], inbuf, MSGSIZE);
    //         printf("% s\n", inbuf);
    //     }
    //     printf("finished reading\n");
    // }
    // return 0;
}