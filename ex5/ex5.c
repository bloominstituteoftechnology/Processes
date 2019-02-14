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
    
    char inbuf[16];
    int p[2];
    
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    
    int rc = fork();
    
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //int wc = waitpid(rc, NULL, 0);
        printf("hello, child here (pid: %d) \n", (int) getpid());
        write(p[1], "Hi there", 16);
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        read(p[0], inbuf, 16);
        printf("%s\n", inbuf);
    }
    return 0;
}
