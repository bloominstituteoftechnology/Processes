// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGsize 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{

    int size = 100;
    int p[2];
    char buffer[size];
    if (pipe(p) < 0) {
          fprintf(stderr, "pipe failde\n");
    }
    int fp = fork();
    if (fp < 0) {
           fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fp == 0) {
        //inside child branch
            printf("Hello from child: %d\n", (int)getpid());
            close(p[0]); // close the read branch
            write(p[1], msg1, size);
            write(p[1], msg2, size);
            write(p[1], msg3, size);
            close(p[1]); // close the write branch
    } else {
        // inside parent branch
           
            close(p[1]);
            int wc = waitpid(fp, NULL, 0);
            printf("Hello from parent: %d\n", (int)getpid());
             for (int i = 0; i < 3; i++) {
                read(p[0], buffer, size);
                printf("%s\n", buffer);
        }
            close(p[0]); 
    }
    

    return 0;
}
