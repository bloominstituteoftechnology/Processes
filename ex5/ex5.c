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
	char inbuf[MSGSIZE];	
	int p[2];
	
	if (pipe(p) < 0) {
		fprintf(stderr, "Unable to Pipe, please try again\n");
		exit(1);
	}
	
	int rc = fork();
	
	if(rc < 0) {
		fprintf(stderr, "There was a problem while forking, please try again later\n");
		exit(1);
	} else if(rc == 0) {
		printf("Writing the messages from the child process with rc %d to the parent\n", rc);
		write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);
	} else {
		printf("In the parent process with rc = %d\n", rc);
		int i;
		for (i = 0; i < 3; i++) {
			read( p[0], inbuf, MSGSIZE);
			printf("%s\n", inbuf);
		}
		printf("%d", rc);
	}
	
    return 0;
}
