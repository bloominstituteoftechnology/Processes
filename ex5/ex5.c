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
    char buffer[MSGSIZE];
    int fd[2];

    if(pipe(fd) < 0) {
        fprintf(stderr, "call the plumber - you have a broken pipe!\n");
        exit(1);
    }

    write(fd[1], msg1, MSGSIZE);
    write(fd[1], msg2, MSGSIZE);
    write(fd[1], msg3, MSGSIZE);

    for( int i = 0; i < 3; i++) {
        read(fd[0], buffer, MSGSIZE);
        printf("%s\n", buffer);
    }
    
    return 0;
}
