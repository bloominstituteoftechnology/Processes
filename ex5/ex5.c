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
    int fds[2];
    char buffer[128];

    pipe(fds);

    if (fork() == 0) {
        read(fds[0], buffer, 128);
        printf("%s\n", buffer);
        read(fds[0], buffer, 128);
        printf("%s\n", buffer);
        read(fds[0], buffer, 128);
        printf("%s\n", buffer);
    } else {
        printf("writing 1\n");
        write(fds[1], msg1, MSGSIZE);
        printf("writing 2\n");
        write(fds[1], msg2, MSGSIZE);
        printf("writing 2\n");
        write(fds[1], msg3, MSGSIZE);
        printf("waiting\n");
        wait(NULL);
    }

    return 0;
}
