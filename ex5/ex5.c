// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main()
{
    // Your code here
    char buffer[MSGSIZE];
    int numberOfBytes;
    int pipes[2];


    if (pipe(pipes) < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if (fork() > 0) {
        printf("child writing to pipe\n");

        write(pipes[1], msg1, MSGSIZE);
        write(pipes[1], msg2, MSGSIZE);
        write(pipes[1], msg3, MSGSIZE);
    }
    else
    {
        close(pipes[1]);

        while ((numberOfBytes = (int) read(pipes[0], buffer, MSGSIZE)) > 0) {
            printf("% s\n", buffer);
        }

        if (0 != numberOfBytes) exit(2);

        printf("Done!!!\n");
    }

    return 0;
}

