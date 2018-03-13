// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    int fds[2];
    char buffer[128];
    fork();
    
    pipe(fds);

    write(fds[1], msg1, 14);
    write(fds[1], msg2, 14);
    write(fds[1], msg3, 14);
    read(fds[0], buffer, 128);

    printf("Read from pipe: %s\n", buffer);

    return 0;
}