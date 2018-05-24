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
    // Your code here

    printf("hello world (pid:%d) \n", (int) getpid());
    int p = fork();
    int pipeline[3];

    if (pipe(pipeline) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        exit(1);
    }

    if (p < 0) 
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (p == 0 )
    {
        printf("hello, I am child (pid:%d\n", (int) getpid());
        write(pipeline[0], msg1, strlen(msg1) + 1);
        write(pipeline[1], msg2, strlen(msg2) + 1);
        write(pipeline[2], msg3, strlen(msg3) + 1);
        close(pipeline[0]);
        close(pipeline[1]);
        close(pipeline[2]);
        printf("Child Wrote Messages \n");

    }
    else
    {
        char data[100];

        printf("hello, I am parent of %d (pid:%d)\n", (int) getpid());

        read(pipeline[0], data, 30);
        read(pipeline[1], data, 30);
        read(pipeline[2], data, 30);
        close(pipeline[0]);
        close(pipeline[1]);
        close(pipeline[2]);
        printf("Parent Read %s\n", data);
    }

    
    
    return 0;
}
