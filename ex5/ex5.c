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
    int pip[4];
    pipe(pip);
    int heckinfork = fork();
    if (heckinfork == 0) {
        close(pip[0]);
        write(pip[0], msg1, MSGSIZE);
        write(pip[1], msg1, MSGSIZE);
        write(pip[2], msg1, MSGSIZE);
        close(pip[2]);
    } else {
        char str[100];
        close(pip[2]);
        read(pip[0], str, 100);
        read(pip[1], str, 100);
        read(pip[2], str, 100);
        close(pip[0]);
        printf("%s", str);
    }
    return 0;
}

