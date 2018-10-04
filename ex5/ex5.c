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
    int    fd[2], nbytes, cpid = fork();
    char   buffer[MSGSIZE];

    if(pipe(fd) < 0)
    {
       perror("pipe");
       exit(1);
    }
    
    pipe(fd);

    if(cpid < 0)
    {
        perror("fork");
        exit(1);
    }

    if(cpid == 0)
    {
        printf("Child writing...\n");
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);
        printf("Finished writing.\n");
    }
    else
    {
        int wc = waitpid(cpid, NULL, 0);
        close(fd[1]);
        printf("Parent reading...\n");
        nbytes = read(fd[0], buffer, MSGSIZE);
        while(nbytes > 0)
        {
            printf("%s\n", buffer);
        }
        printf("Finished reading.\n");
    }

    return 0;
}
