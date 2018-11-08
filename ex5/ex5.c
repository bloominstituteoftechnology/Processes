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
    // Your code here
    
    char inbuf[MSGSIZE]; // buffer that will hold the incoming data that is being written
    int p[2]; // a two-element array to  hold the read and write file descriptors that are used by the pipe

    if(pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int fifth = fork();

    if(fifth< 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if(fifth == 0) {
        printf("Hello, child here. (pid: %d) \n", (int) getpid());
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else {
        waitpid(fifth, NULL, 0);
        printf("Hello, parent here. (pid: %d) \n", (int) getpid());
        for(int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }

    return 0;
}
