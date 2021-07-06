// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

//a. We've been able to fork and have the child write to a pipe
//b. Have the parent read from the pipe. 
//c. Why do we need to know this?
//d. If processes are independent, then pipes are good for connecting them
//e. If you wanted them to be independent, then why connect them?

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
    char inbuf[MSGSIZE];    // a buffer that will hold the incoming data that is being written
    int p[2];               // a two-element array to hold the read and write file descriptors that are used by the pipe   

    // establish our pipe, passing it the p array so that it gets populated by the read and write file descriptors
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    printf("Before forking pid: %d\n", (int) getpid());
    printf("\np[0]: %d\n", p[0]);
    printf("p[1]: %d\n", p[1]);
    pid_t pid = fork();

    if (pid < 0) //fork failed
    {
        exit(1);
    } 
    else if (pid == 0) //child process
    {
        printf("AFTER forking CHILD pid: %d\n", (int) getpid());

        // write 16 bytes of data to the write file descriptor
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);

    }
    else {
        //wait for child to complete writing into the pipe
        waitpid(pid, NULL, 0); 

        printf("AFTER forking PARENT pid: %d\n", (int) getpid());
        for (int i = 0; i < 3; i++) {
            // read 16 bytes of data from the read file descriptor 
            read(p[0], inbuf, MSGSIZE);
            printf("Parent writes: %s\n", inbuf);
        }
    }
    
    return 0;
}
