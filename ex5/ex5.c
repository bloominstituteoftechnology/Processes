// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    char* buf[MSGSIZE];
    pid_t pid;
    int pipefd[2];

    int ret = pipe(pipefd);
    
    if (ret == -1)
    {
        perror("Pipe error.");
        exit(1);
    }
    
    pid = fork();

    if (pid == 0)
    {
        pid = getpid();
        printf("Input(%i): %s\n", pid, buf);
        write(pipefd[1], "Hello world.", 12);
    } else {
        pid = getpid();
        wait(NULL);
        read(pipefd[0], buf, 15);
        printf("Output(%i): %s\n", pid, buf);
    }

    return 0;
}
