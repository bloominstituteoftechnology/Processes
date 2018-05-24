// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16 // define a  constant message size for each message

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    // Your code here
    // a buffer that will hold the incoming data that is being written
    char inbuf[MSGSIZE]; 
    
    // a two-elemnt array to hold the read and write file descriptors that are used by the pipe
    int p[2]; 

    // create a fork
    int rc = fork();

    // child process starts

    // establish our pipe, passing it the p array so that it gets populated by the read and write file descriptors
    if (pipe(p) < 0){
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }  

    if(rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0) {
        // child process satisfies this branch
        printf("Hello! Child here (pid: %d) \n", (int) getpid());

        // write 16 bytes of data to the write file descriptor
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);

        for(int i = 0; i < 3; i++) {
            // read 16 bytes of data from the read file descriptor
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
   }else{
        int wc = waitpid(rc, NULL, 0); // waitpid call added here
        printf("Goodbye!, parent here (pid: %d) of child %d\n", getpid(), rc);
    }

    return 0;
}
