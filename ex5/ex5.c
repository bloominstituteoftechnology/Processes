// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";
 
int main()
{
    char size[MSGSIZE];
    int p[2], pid, numBytes;
 
    if (pipe(p) < 0) 
    {
        fprintf(stderr, "pipe failed");
        exit(1);
    }
 
    if ((pid = fork()) > 0) 
    {
        printf("Child writing to pipe\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
 
        close(p[1]);
        wait(NULL);
    }
 
    else 
    {
        close(p[1]);

        printf("Parent reading from pipe\n");

        while ((numBytes = read(p[0], size, MSGSIZE)) > 0) 
        {
            printf("% s\n", size);
        }
        if (numBytes != 0) 
        {
            exit(2);
        }
        printf("Finished reading\n");
    }
    return 0;
