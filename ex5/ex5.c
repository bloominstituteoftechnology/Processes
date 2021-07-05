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
    char inbuf[MSGSIZE];
    int pipearr[2];  // Used to store two ends of first pipe 
    if (pipe(pipearr) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    // Your code here
    int child = fork();

    if (child == 0){
        write(pipearr[1], msg1, MSGSIZE); 
        write(pipearr[1], msg2, MSGSIZE); 
        write(pipearr[1], msg3, MSGSIZE); 
        close(pipearr[1]);
    }
    else{
        for (int i = 0; i < 3; i++) {
        // read 16 bytes of data from the read file descriptor 
        read(pipearr[0], inbuf, MSGSIZE);
        printf("%s \n", inbuf);
        }
        close(pipearr[0]); 

    }

    return 0;
}
