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
    int childpid;
    int rc = fork();
    if(rc == 0){
        childpid = getpid();
    } else if(rc < 0){
        printf("u done wrong kid!\n");
    }
    char inbuf[MSGSIZE];    // a buffer that will hold the incoming data that is being written
    int p[2];

    if(pipe(p) < 0)
    {
        printf("pipe did nothing wrong, y did you murder it?! :(\n");
    }

    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    //_Exit(0);
    if(getpid() == childpid){
        exit(1);
    }
    for (int i = 0; i < 3; i++) {
        // read 16 bytes of data from the read file descriptor 
        read(p[0], inbuf, MSGSIZE);
        printf("string: %s  pid:%d\n", inbuf, getpid());
    }
    return 0;
}
