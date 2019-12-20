// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here

	// another program that uses fork()
	printf("forking...\n");

	int rc = fork();

	if (rc < 0) {
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child process should print hello
		printf("hello\n");
	} else {
		// parent process should print goodbye
		int wc = waitpid(rc, NULL, 0);
		printf("goodbye\n");
	}
	
	
	// ensure that the child process always prints first
    return 0;
}
