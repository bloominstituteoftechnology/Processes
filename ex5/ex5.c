// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1
#define MSGSIZE 64

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    int pipes[2];
    pipe(pipes);
    
    int pid = fork();
    if (pid) { // parent reads from pipe
        close(pipes[WRITE]);
        char buf[MSGSIZE];
        for (size_t i = 0; i < 3; i++)
        {
            read(pipes[READ], buf, MSGSIZE);
            printf("%s\n", buf);
        }
    } else {  // child writes to pipe
        close(pipes[READ]);
        write(pipes[WRITE], msg1, MSGSIZE);
        write(pipes[WRITE], msg2, MSGSIZE);
        write(pipes[WRITE], msg3, MSGSIZE);
    }

    return EXIT_SUCCESS;
}
