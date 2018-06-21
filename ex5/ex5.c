// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "Hello World #1";
char* msg2 = "Hello World #2";
char* msg3 = "Hello World #3";

int main()
{
    // Your code here
    // https://www.geeksforgeeks.org/pipe-system-call/
 	char inbuf[MSGSIZE]; // Buffer that will hold the incoming data that is being written
	int p[2]; // Two-element array to hold the read & write file descriptors that are used by the pipe

    // Establish our pipe, passing in the P array so that it gets
    // populated by the read & write file descriptors
	if (pipe(p) < 0) { // Pipe Fail
		fprintf(stderr, "pipe failed\n");
		exit(2); // 2 instead of 1 so we know if the pipe or fork failed since err is 1
	}

	int child = fork();
	
    if (child < 0) { // Fork Fail
		fprintf(stderr, "fork failed\n");
		exit(1);

    return 0;
}
