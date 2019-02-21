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
    char buf[MSGSIZE];
    int p[2];               // a two-element array to hold the read and write file descriptors that are used by the pipe   

    // establish our pipe, passing it the p array so that it gets populated by the read and write file descriptors
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }else {
        int new_process = fork();
    
        if (new_process){
            printf("hello from child\n");
             write(p[1], msg1, MSGSIZE);
             write(p[1], msg2, MSGSIZE);
             write(p[1], msg3, MSGSIZE);
            printf("goodbye from child\n");

        } else {
            printf("hello from parent\n");
            for (int i = 0; i < 3; i++) 
            {
            // read 16 bytes of data from the read file descriptor 
            read(p[0], buf, MSGSIZE);
            printf("\t%s\n", buf);
            }
            printf("goodbye from parent\n");
        }
    }

    return 0;
}
