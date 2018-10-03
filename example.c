#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16 // define a constant message size for each message

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    char inbuf[MSGSIZE]; // a buffer that will hold the incoming data that is being written
    int p[2];            // a two-element array to hold the read and write file descriptors that are used by the pipe

    // establish our pipe, passing it the p array so that it gets populated by the read and write file descriptors
    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    // write 16 bytes of data to the write file descriptor
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    for (int i = 0; i < 3; i++)
    {
        // read 16 bytes of data from the read file descriptor
        read(p[0], inbuf, MSGSIZE);
        printf("% s\n", inbuf);
    }

    return 0;
}