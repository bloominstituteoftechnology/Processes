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
    int p[2];
    pipe(p);
    char inputbuff[MSGSIZE];

    int rc = fork();

    if(rc < 0){
        printf("fork failed\n");
        exit(1);
    }else if (rc == 0){
        // In  Child fork, send messages through pipe
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
 
    }else{
        // In parent fork, save messages from pipe to input buffer, print.
        for(int i = 0; i < 3; i++)
        {
            read(p[0], inputbuff, MSGSIZE);
            printf("Message: %s\n", inputbuff);
        }
        
    }
    
    return 0;
}
