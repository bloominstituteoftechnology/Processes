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
//    printf("Parent %d\n", (int) getpid());
    
    char inbuffer[MSGSIZE];
    int p[2];
    
    pipe(p);
    
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    
    pid_t rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
//        int wc = waitpid(rc, NULL, 0);
        
        for (int index = 0; index < 3; index++) {
            read(p[0], inbuffer, MSGSIZE);
            printf("%s\n", inbuffer);
        }
    } 
    return 0;
}
