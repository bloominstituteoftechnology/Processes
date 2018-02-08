// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> 

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main()
{
    int p[2];
    char inbuf[MSGSIZE]; 
    
    int childProcess = fork();
    if (childProcess < 0) {
        fprintf(stderr, "Error: Could not fork!");
    } else if (childProcess == 0){
        // Your code here
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        close(p[1]);
        wait(NULL);
    } else {
        close(p[1]);
        int wc = waitpid(childProcess, NULL, 0);
        if (pipe(p) < 0) {
            fprintf(stderr, "pipe failed\n");
            exit(1);
        }
        for (int i = 0; i < 3; i++) {
            // read 16 bytes of data from the read file descriptor 
           read(p[i], inbuf, MSGSIZE);
        }
    } 
    return 0;
}
