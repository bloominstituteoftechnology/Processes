// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// this is a constant size for the messages
#define MSGSIZE 16

// here are our three messages
char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    // the buffer that holds data to be written
    char firehose[MSGSIZE];

    // 2 element array holds read/write descriptors used by the pipe
    int p[2];

    // if the pipe is less than 0, you ain't got no pipe
    if (pipe(p) < 0) {
        fprintf(stderr, "no flow, pipe failed\n");
        exit(1);
    }
    // fork is called after the creation of the pipe, which allows parent and child to communicate
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "no fork for you\n");
        exit(1);
    } else if (rc == 0) {
        // write the messages into pipe element 2, command 1 is for writing
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        // remember that when you use a for loop, you need to use -std=c99 in your gcc call
        for (int i = 0; i < 3; i++) {
            // read the elements as they're being buffered by the firehose, command 0 is for reading
            read(p[0], firehose, MSGSIZE);
            printf("%s\n", firehose);
        }
    }

    return 0;
}
