// Write a program that forks a child and creates a shared p
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{

char buf[MSGSIZE];
int p[2];
int status;

if (pipe(p) < 0) {
    fprintf(stderr, "pipe failed\n");
    exit(1);
    }
    
int rc = fork();
    
if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
    } else if (rc == 0) {
        printf("Child 1 pid: %d, start to write\n", (int) getpid());
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("Child 2 pid: %d, end of write\n", (int) getpid());
    } else {
        while (waitpid(fk, &status, WNOHANG) == 0)
        {
            sleep(1);
        }
        
        printf("Parent 1 pid: %d, start to read\n", (int) getpid());
        
        for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        
        printf("Parent 2 pid: %d, end of read\n", (int) getpid());
    }
    return 0;
}
