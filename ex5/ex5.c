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
    pid_t p;
    char buffer[MSGSIZE];
    int pipe1[2], pipe2[2];

    if (pipe(pipe1) < 0)
    {
        fprintf(stderr, "Pipe failed.");
        return 1;
    }
    if (pipe(pipe2) < 0)
    {
        fprintf(stderr, "Pipe failed.");
        return 1;
    }

    p = fork();

    if (p < 0)
    {
        fprintf(stderr, "Fork failed.");
        return 1;
    }

    if (p == 0) // child process
    {
        close(pipe1[0]); // close read channel of child pipe

        // write 16 bytes of data to the write file descriptor
        write(pipe1[1], msg1, MSGSIZE);
        write(pipe1[1], msg2, MSGSIZE);
        write(pipe1[1], msg3, MSGSIZE);

        close(pipe1[1]); // close write channel of child pipe
    } else // parent process
    {
        waitpid(p, NULL, 0); // wait for child

        close(pipe2[1]); // close write channel of parent pipe

        for (int i = 0; i < 3; i++) {
            read(pipe1[0], buffer, MSGSIZE); // read 16 bytes of data from the read file descriptor
            printf("%s\n", buffer);
        }

        close(pipe2[0]); // close read channel of parent pipe
    }

    return 0;
}
