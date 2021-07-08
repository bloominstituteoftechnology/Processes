// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//Program defines a constant size for messages to be 16 bytes

#define MSGSIZE 16
//Program declares three char pointers that point to string arrays to be sent during execution of the program

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    //Program creates a temporary storage location (buffer) for the messages to be transferred

    // Your code here
    char inbuf[MSGSIZE];
    int p[2];
    //Program then establishes a pipe, passing in the two-element array being used to hold read/write file descriptors
//If the pipe returns less than one, it is a failure condition, so it prints to stderr and exits


    if (pipe(p) < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
}
//If the pipe is successful, the program then performs a fork call
//If the result of the fork call is less than 0, the program prints a failure message to stderr and exits

    int rc = fork();
    if (rc < 0){
        fprint(stderr, "fork failed\n");
        exit(2);
    }
    //If the result of the fork call is 0, it means that it is currently in the child process
//The program then prints a message with the current pid
//  The child process writes to the write file descriptor.
//The program then prints a message with the current pid.
//Meanwhile, the parent process has been held up by use of the waitpid command, where it was waiting until the child process finished executing before continuing.
//Now that the parent process can do its thing, it reads from the read file descriptor up to the stated message size.
//The program then prints the current pid followed by the messages that had been transferred along the pipe.
    else if (rc == 0 ) {
        int wc = waitpid(rc, NULL, 0);
        
        close(p[1]);
        printf("parent reading from pipe\n");

        while (read(p[0], inbuf, MSGSIZE) > 0){
            printf("%s\n", inbuf);
        }
        printf("finished reading\n");
    
    
}
    return 0;
}
