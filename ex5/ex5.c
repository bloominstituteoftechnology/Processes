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
    char inbuf[MSGSIZE];
    int p[2], pid, nbytes;
    int rc = fork();

    if (pipe(p) < 0) {
        fprintf(stderr, "Pipe Failed\n");
        exit(1);
    }

    if ((rc = fork()) > 0) {
        printf("Parent writing to pipe\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        close(p[1]);
        printf("Child reading from pipe\n");

        while (read(p[0], inbuf, MSGSIZE) > 0) {
            printf("%s\n", inbuf);
        }

        printf("Finished reading\n");
    }


    return 0;
}
