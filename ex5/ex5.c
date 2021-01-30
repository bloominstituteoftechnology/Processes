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
    char inbuf[1024];
    int p[2];
    if (pipe(p) < 0) {
        printf("You piped yourself into a corner my dude!");
        exit(1);
    }
    int responseFromFork = fork();
    if (responseFromFork < 0) {
        fprintf(stderr, "You forked up!\n");
        exit(1);
    } else if (responseFromFork == 0) {
        printf("This is the child thread\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        printf("This is the parent thread.\n");
        for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }
    
    return 0;
}
