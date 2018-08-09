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
    char inbuf[MSGSIZE];
    int i[2];

    printf("%d is currently running\n", (int) getpid());

    if (pipe(i) < 0) {
        fprintf(stderr, "Failed pipe\n");
        exit(1);
    } else {
        int rc = fork();
    

    if (rc < 0) {
        fprintf(stderr, "Failed fork\n");
        exit(1);
    } else if (rc == 0) {
        printf("%d will run before writing\n", (int) getpid());
        write(i[1], msg1, MSGSIZE);
        write(i[1], msg2, MSGSIZE);
        write(i[1], msg3, MSGSIZE);
        printf("%d will run after writing\n", (int) getpid());
    } else {
        waitpid(rc, NULL, 0);
        for (int i = 0; i < 3; i++) {
            read(i[0], inbuf, MSGSIZE);
            printf("%d returns %s\n", (int), getpid(), inbuf);
        }
    }
    }
    return 0;
}
