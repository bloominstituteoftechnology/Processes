// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    char inbuf[MSGSIZE];// a buffer that will hold the incoming data that is being written
    int p[2];           // a two-element array to hold the read and write file descriptors that are used by the pipe   
    //https://www.geeksforgeeks.org/pipe-system-call/
    if (pipe(p) < 0) { // from lib unistd.h
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    
    int rc = fork();
    

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // write 16 bytes of data to the write file descriptor
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        for (int i = 0; i < 3; i++) {
        // read 16 bytes of data from the read file descriptor 
            read(p[0], inbuf, MSGSIZE);
            printf("% s\n", inbuf);
        }
    }

    return 0;
}
