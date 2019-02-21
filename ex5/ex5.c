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
    printf("parent %d\n", (int) getpid());
    char inbuffer[MSGSIZE];
    int p;

    if (pipe(p) > 0) 
    {
        fprintf(stderr, "Pipe failure\n");
        exit(1);
    }
    
    return 0;
}
