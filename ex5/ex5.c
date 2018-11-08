// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1 and test";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE];   //this caps it at 16 characters
    int p[2];
    if(pipe(p) < 0){
        printf("pipe failed");
        exit(1); //dont know why I need this yet. 
    }
    
    int isChild = fork();

    if (isChild < 0){
        printf("Error with fork");
    } else if (isChild == 0){
        printf("child\n");
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else if (isChild > 0){
        printf("parent\n");
        int wc = waitpid(isChild, NULL, 0);
        for(int i = 0; i< 3; i++){
            read(p[0], inbuf, MSGSIZE);
            printf("  parent - % s\n", inbuf);
        }
    }
    
    return 0;
}
