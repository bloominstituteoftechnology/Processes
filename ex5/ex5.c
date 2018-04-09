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
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Process Failed.\n");
        exit(1);
    } else if (rc == 0) {
        write(pipe1[1], msg1, strlen(msg1));
        read(pipe2[0], buffer, 128);
        printf("Child read from Pipe 2: %s\n", buffer);
    } else {
        read(pipe1[0], buffer, 128);
        write(pipe2[1], msg2, strlen(msg2));

        printf("Read from Pipe 1: %s\n", buffer);
    }
    
    return 0;
}
