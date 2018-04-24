// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    // Your code here
    // initialize char variable to hold the 'write' and 'read' string
    char inbuf[MSGSIZE];
    // size of array for pipe read and write
    int p[2];
    
	if(pipe(p) < 0){
		fprintf(stderr, "pipe failed\n");
        exit(1);
	}

    // clone a process
	int rc = fork();

	if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    
    	printf("from child, writing msg to pipe\n");
        // write messages to array 1 in queue
        write(p[1], msg1, MSGSIZE);
    	write(p[1], msg2, MSGSIZE);
    	write(p[1], msg3, MSGSIZE);

    } else {
        // wait for the child (write) process to finish
    	int wc = waitpid(rc, NULL, 0);

    	printf("from parent, reading msg from pipe\n");
    	// iterate three times, read the message from the pipe (queue) and print them out
    	for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
	        printf("inbuf msg: %s\n", inbuf);
	    };
    }
    return 0;
}
