// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 
// child w-----------pipe------------r parent

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main(void)
{
    char buffer[MSGSIZE]; //buffer that will hold the incoming data that is being written
    int p[2]; //two-element array to hold read/p[0] and write/p[1] file descriptors that are used by pipe()

    int child = fork();

    if (child > 0) //parent
    {
        int wc = waitpid(child, NULL, 0);    // `waitpid` call added here
        printf("Parent is reading 16 bytes of data from child.");
        read(p[0], buffer, MSGSIZE);
        printf("\nParent reads that child recently wrote, %s\n", buffer);   
        
    }
    else if (child == 0) //child
    {
        printf("Child wrote 16 bytes of data to parent. ");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("\nWhat else do you want to write to parent? \n");

    }
    else
    {
        fprintf(stderr, "Fork Failed!\n");
        exit(1);
    }

    if (pipe(p) < 0)
    {
        fprintf(stderr, "Pipe Failed!\n");
        exit(1);
    }
    
    return 0;
}
