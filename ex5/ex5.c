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
    int pipe1[2];
    int pipe2[2];
    char buffer[128];

    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {
        write(pipe1[1], "Hello, World", 14);

        read(pipe1[0], buffer, 128);

        printf("Child read from pipe1: %s\n", buffer);
    } else {
        write(pipe2[1], "Thank you", 20);
        read(pipe2[0], buffer, 128);

        printf("Read from pipe2: %s\n", buffer);
    }
    
    return 0;
}
