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
    char inbuf[MSGSIZE];    // a buffer that will hold the incoming data that is being written
    int p[2];               // a two-element array with 0 + 1 - represents the input and output of pipe 

    // establish our pipe,checks for failure
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork(); 
    
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");//prints to standard error 
        exit(1);

    } else if (rc == 0) {    // child reads message
        for (int i = 0; i < 3; i++) {
        read(p[0], inbuf, MSGSIZE); // 0 represents output
        printf("% s\n", inbuf);
        }
    

    } else { //parent writes message 

        write(p[1], msg1, MSGSIZE);// 1 represents input
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
     
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

   

   
    
    return 0;
}
