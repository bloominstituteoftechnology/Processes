// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello child #1\n";
char *msg2 = "hello child #2\n";
char *msg3 = "hello child #3\n";

int main(void)
{
    char buffer[MSGSIZE]; // A buffer for incoming data
    int p[2];             // array
    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    // Your code here
    int rc = fork();
    if (rc == 0)
    {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("Child process checking in.\n");
    }
    if (rc > 0)
    {
        // Parent process
        for (int i = 0; i < 3; i++)
        {
            read(p[0], buffer, MSGSIZE);
            printf("% s\n", buffer);
        }
    }

    return 0;
}
