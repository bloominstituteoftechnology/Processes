// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    int pipe1[2];
    int pipe2[2];
    char buffer[128];

    pipe(pipe1);
    pipe(pipe2);
    int forked = fork();

    if (forked < 0)
    {
        fprintf(stderr, "Fork has failed\n");
        exit(1);
    } else if (forked == 0)
    {
        write(pipe1[1], "Hello World!", 14);
        read(pipe2[0], buffer, 128);
        printf("Child from pipe2: %s\n", buffer);
    } else
    {
        read(pipe1[0], buffer, 128);
        write(pipe2[1], "Complete", 7);
        printf("Pipe1: %s\n", buffer);
    }
    
    return 0;
}
