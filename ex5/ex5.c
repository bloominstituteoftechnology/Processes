// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE * 3];
    int p[2];
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char concatMessages[MSGSIZE * 3];
        strcat(concatMessages, msg1);
        strcat(concatMessages, msg2);
        strcat(concatMessages, msg3);
        printf("this should be seen\n");
        write(p[1], concatMessages, MSGSIZE * 3);
        close(p[1]);
    } else {
        int wc = waitpid(rc, NULL, 0);
        read(p[0], inbuf, MSGSIZE * 3);
        printf("%s\n", inbuf);
        close(p[0]);
    }
    return 0;
}
