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
    // init an inbug
    char inbuf[MSGSIZE];
    // init an array to hold read/write file handles
    int p[2];
    // call pipe and pass in p, check if it's value is less than 0
    if (pipe(p) < 0)
    {
        // standard error handling
        fprintf(stderr, "pipe failed\n");
        // break out of the loop
        exit(1);
    }
    // init the child process
    // forking needs to happen after the pipe is initialized
    // because->both processes are going to have copies of the
    // file descriptors created by the pipe
    int rc = fork();

    if (rc < 0)
    {
        // different error for if the fork fails
        fprintf(stderr, "fork failed\n");
        // break out with the appropriate code
        exit(2);
    }

    else if (rc == 0)
    {
        // if rc value is zero, the child was made
        printf("child writing to pipe\n");
        // write the message values to the pipe
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }

    else
    {
        // call wc to have the parent wait
        int wc = waitpid(rc, NULL, 0);
        // close the right end of the pipe
        close(p[1]);
        printf("parent reading from pipe\n");
        // read returns number of bytes read
        // messages get queued, and read off in the length of MSGSIZE
        while (read(p[0], inbuf, MSGSIZE) > 0)
        {
            // print the messages
            printf("%s\n", inbuf);
        }
        // let the user know the program is done running
        printf("finished reading\n");
    }
    
    return 0;
}
