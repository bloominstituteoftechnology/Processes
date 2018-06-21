// Write a program that forks a child and creates a shared pipe
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
	//Your code here
	//buffer that holds incoming data
	  char inbuf[MSGSIZE];
	  // instantiate pipe where p[0] is to read and p[1] is to write
		int fd[2];

		// error check: pipe fails
		if (pipe(fd) == -1) {
			printf("pipe failed");
			return 1;
		}

		printf("pid before fork(): %d\n", (int) getpid());
		int rc = fork();

	  if (rc < 0) {
	    fprintf(stderr, "fork blew up, try again! \n");
	    exit(1);
	  } else if (rc == 0) {
	  	printf("child pid: %d\n", (int) getpid());
	  	// close reading end of pipe
	  	close(fd[0]);
	  	// write messages
	  	write(fd[1], msg1, MSGSIZE);
	  	write(fd[1], msg2, MSGSIZE);
	  	write(fd[1], msg3, MSGSIZE);
	  	// close writing end of pipe
	  	close(fd[1]);
	  } else {
	  	printf("parent pid: %d\n", (int) getpid());
	  	int wc = waitpid(rc, NULL, 0);
	  	wait(NULL);
	  	// close writing end of pipe
	  	close(fd[1]);
	  	// read messages from the read file descriptor
	  	for (int i = 0; i < 3; i++) {
	  		// read data from inbuf
	  		read(fd[0], inbuf, MSGSIZE);
	  		printf("%s\n", inbuf);
	  	}
	  	// close reading end
	  	close(fd[0]);
	  }

	  return 0;

	// // ~~~ Second Solution ~~~
	// // Your code here
	// char inbuf[MSGSIZE]; // Buffer that holds incoming data being written
	// int p[2];			 // Two-element array to hold the read and write file descriptors that are used by the pipe.

	// // Establish pipe, pass to p array so that it gets populated by the read and write descriptors.
	// if (pipe(p) < 0)
	// {
	// 	fprintf(stderr, "Pipe Failed\n");
	// 	exit(1);
	// }

	// // Begin fork
	// int rc = fork(); // Fork
	// if (rc < 0)		 // Fork Failed
	// {
	// 	fprintf(stderr, "Fork Failed\n");
	// 	exit(1);
	// }
	// else if (rc == 0)
	// {
	// 	printf("Hello from child process, pid: %d\n", (int)getpid());
	// 	//close(p[0]);

	// 	// Write 16 bytes of data to the write file descriptor
	// 	write(p[1], msg1, MSGSIZE);
	// 	write(p[1], msg2, MSGSIZE);
	// 	write(p[1], msg3, MSGSIZE);
	// 	close(p[1]);
	// }
	// else
	// {
	// 	printf("Hello from parent process, pid: %d\n", (int)getpid());

	// 	// Read 16 bytes of data to the read file descriptor
	// 	for (int i = 0; i < 3; i++)
	// 	{
	// 		read(p[0], inbuf, MSGSIZE);
	// 		printf("%s\n", inbuf);
	// 	}
	// 	close(p[0]);
	// }

	// return 0;
}
