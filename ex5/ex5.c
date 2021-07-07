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
    printf("parent %d\n", (int) getpid());
    char inbuffer[MSGSIZE];
    int p[2];

    if (pipe(p) < 0) 
    {
        fprintf(stderr, "Pipe failure\n");
        exit(1);
    }
    int rc = fork();
    if (rc < 0) 
    {
        fprintf(stderr, "Fork failure\n");
        exit(2);
    }
    else if (rc == 0)
    {
        printf("Child writing to pipe\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else 
    {
        close(p[1]); //close write branch
        wait(NULL); //not necessary b/c processes can run at same time but doesnt hurt
        //ssize_t read(int fd, void *buf, size_t count);
        for (int i = 0; i < 3; i++) 
        {
            read(p[0], inbuffer, MSGSIZE);
            printf("%s\n", inbuffer);
        }
        close(p[0]);  //close read
    }
    
    return 0;
}
