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
    // Your code here
    char buffer[MSGSIZE];
    int p[2];

    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {
        printf("Fork failed.");
        exit(2);
    } else if (rc == 0) {
        printf("In child, writing messages.\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        wait(NULL);
        printf("In parent, reading messages.\n");
        for (int i = 0; i < 3; i++) {
            read(p[0], buffer, MSGSIZE);
            printf("%s\n", buffer);
        }
    }

    return 0;
}
