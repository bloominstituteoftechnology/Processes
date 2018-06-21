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
    // Your code here
    printf("Starting program.\n");
    char inbuf[MSGSIZE];
    int p[2];
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc=fork();
    if(rc<0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child process
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("Child complete.\n");
    } else {  // parent process
        int wc = waitpid(rc, NULL, 0);
        for(int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        printf("Parent complete.\n");
    }
    
    return 0;
}
