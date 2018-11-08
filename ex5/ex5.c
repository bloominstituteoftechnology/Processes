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
    int p[2];

    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d)\n", (int) getpid());
        char* msg2 = "hello world #2.1";
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("goodbye, child process completed (pid: %d)\n", (int) getpid());


    } else {
        wait(NULL);
        printf("parent start(pid: %d)\n", (int) getpid());
        for (int i = 0; i < 3; i++) {
            // read 16 bytes of data from the read file descriptor 
            read(p[0], inbuf, MSGSIZE);
            printf("% s\n", inbuf);
        }
        printf("parent end\n");

    }
    
    return 0;
}
