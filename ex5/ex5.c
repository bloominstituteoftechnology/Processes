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

int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2]; 

    if (pipe(p) < 0) {
        fprintf(stderr, "Pipe failed!\n");
        exit(1); 
    } 

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    } else if (pid == 0) {
        printf("Child sending messages through pipe.\n");
        write(p[1], msg1, MSGSIZE); 
        write(p[1], msg2, MSGSIZE); 
        write(p[1], msg3, MSGSIZE); 
    } else {
        waitpid(pid, NULL, 0);
        close(p[1]);
        printf("Parent reading from pipe.\n");
        while (read(p[0], inbuf, MSGSIZE) > 0) {
            printf("%s\n", inbuf);
        }
    }

    return 0; 
} 
