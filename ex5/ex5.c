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
    int f[2];
    int i;

    if (pipe(f) < 0) {
        fprintf(stderr, "Pipe is broken.\n");
        exit(1);
    }

    int forking = fork();

    if (forking < 0) {
        fprintf(stderr, "Forking error.\n");
    } else if (forking == 0) {

        printf("Child activity.\n");
        write(f[1], msg1, MSGSIZE);
        write(f[1], msg2, MSGSIZE);
        write(f[1], msg3, MSGSIZE);
        
    } else {

        printf("Parent activity.\n");
        for (i = 0; i < 3; i ++) {
            
            read(f[0], buffer, MSGSIZE);
            printf("%s\n", buffer);
        
        }
    }
    
    return 0;
}
