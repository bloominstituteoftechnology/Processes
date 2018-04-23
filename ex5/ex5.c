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
    char inbuf[MSGSIZE];
    int p[2];
    int rc;
	
	if(pipe(p) < 0){
		fprintf(stderr, "pipe failed\n");
        exit(1);
	}

	if (rc = fork() < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc = fork() > 0) {    // child process satisfies this branch
    	printf("from child, writing msg to pipe\n");
        write(p[1], msg1, MSGSIZE);
    	write(p[1], msg2, MSGSIZE);
    	write(p[1], msg3, MSGSIZE);
    	printf("child wrote msg to pipe\n");

    } else {
    	// int wc = waitpid(rc = fork(), NULL, 0);
    	printf("from parent, reading msg from pipe\n");
    	close(p[1]);
    	for (int i = 0; i < 3; i++) {
    		printf("begining of loop: %d\n", i);
	        read(p[0], inbuf, MSGSIZE);
	        printf("inbuf msg: %s\n", inbuf);
	        printf("end of each loop: %d\n", i);
	    }
    }
    return 0;
}
