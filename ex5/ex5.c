// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

// good resource/notes
// https://www.geeksforgeeks.org/pipe-system-call/

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
    // hold our read/write file descriptors
    char inbuf[MSGSIZE]; //this is simply an array with its parameters defined by MSGSIZE, which is brought in/defined above
    int p[2];
    // declare number of bytes, for while loop below
    int nbytes;

    if (pipe(p) < 0) {
        fprintf(stderr, "pipe FAILED\n");
        // giving different error/exit(numbers) is best practice
        // plus more precise in error handling: this is 2 pipe fail, is 1 is fork fail.
        exit(2);
    }
    int rc = fork();
    // error handling
    if (rc < 0) {
        fprintf(stderr, "fork FAILED!!!\n");
        exit(1);
    } else if (rc == 0) {
        // CHILD
        printf("child is writing to pipe\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        // PARENT
        // close the "right" end of the pipe, parent is not going to be writing to it.
        close(p[1]);
        printf("parent is reading from pipe\n");
        // because we don't know, usually how amny messages will be passed, we use
        // a while loop, and base it off the number of bytes that get read by the read
        // function.
        while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0) {
            printf("%s\n", inbuf);
        }
        printf("Finished reading\n");
    }

    return 0;
}
