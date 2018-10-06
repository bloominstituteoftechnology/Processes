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
    // Your code here
    char buffer[MSGSIZE];
    int pipes[2];
    
    if(pipe(pipes) < 0){
        printf("No data to pipe.");
        exit(1);
    }

    int f = fork();

    if(f < 0){
        printf("Fork failed!");
        exit(2);
    } else if(f == 0){
        printf("Child fork\n");
        write(pipes[1], msg1, MSGSIZE);
        write(pipes[1], msg2, MSGSIZE);
        write(pipes[1], msg3, MSGSIZE);
    } else {
        wait(NULL);
        close(pipes[1]);
        printf("Parent fork\n");

        while(read(pipes[0], buffer, MSGSIZE) > 0){
            printf("Pipe from parent %s\n", buffer);
        }
    }
    return 0;
}
