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
    char inbuf[MSGSIZE];
    int p[2];

    if(pipe(p) < 0) {
        fprintf(stderr, "Pipe error occured\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid;  
    pid = fork();
    if (pid < 0) {
        printf("Fork error occured\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        // wait(NULL); // if this is commentted result will be different.
        int wc = waitpid(pid, NULL, 0);
        printf("From parent (pid %d): Child (pid %d) wrote: \n", (int) getpid(), pid);      // x = 10
        for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }
  return 0;
}
