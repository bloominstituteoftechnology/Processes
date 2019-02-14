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
    // Setup pipe
    char inbuf[MSGSIZE];
    int p[2];

    // Ensure pipe doesn't fail
    if (pipe(p) < 0)
    {
        fprintf(stderr, "Pipe Failed\n");
        exit(1);
    }

    // Create child process
    int child_process = fork();
    
    if (child_process < 0)
    {
        // Failure to fork
        fprintf(stderr, "Failure to fork!\n");
        exit(1);
    }
    else if (child_process == 0)
    {
        // Fork succeeds, write to pipe
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        // Parent context
        // Wait for child to finish writing to pipe
        int wc = waitpid(child_process, NULL, 0);
        // Child finished, read from pipe buffer
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%s \n", inbuf);
        }
    }

    return 0;
}
