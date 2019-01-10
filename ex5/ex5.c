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
    char inbuf[MSGSIZE]; // our buffer that holds incoming data to be written
    int p[2]; // a two-element array that holds read and read write descriptors

    if(pipe(p) < 0){
        fprintf(stderr, "Pipe initialization failed.\n");
        exit(1);
    } else {
        int forked = fork();
        if(forked < 0){
            fprintf(stderr, "Fork attempt failed.\n");
            exit(1);
        } else if(forked == 0){
            // if fork creates child process, write messages inside pipe during child process
            printf("Child process writing...\n");
            write(p[1], msg1, MSGSIZE); // we use p[1] for each since they are write messages. p[0] is our read buffer.
            write(p[1], msg2, MSGSIZE);
            write(p[1], msg3, MSGSIZE);
        } else {
            for(int i = 0; i < 3; i++){ // begin the read process once child process completes
                read(p[0], inbuf, MSGSIZE);
                printf("%s\n", inbuf);
            }
        }
    }

    return 0;
}
