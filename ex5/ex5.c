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

int main()
{
    int p[2];
    char inbuf[MSGSIZE];

    int childProcess = fork();
    if (childProcess < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (childProcess == 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[2], msg2, MSGSIZE);
        write(p[3], msg3, MSGSIZE);
        close(p[1]);
        wait(NULL);
    } else {
        close(p[1]);
        int w = waitpid(childProcess, NULL, 0);
        if (pipe(p) < 0) {
            fprintf(stderr, "pipe failed\n");
            exit(1);
        }
        for (int i = 0; i < 3; i++) {
            read(p[i], inbuf, MSGSIZE);
        }
    }
    return 0;
}
