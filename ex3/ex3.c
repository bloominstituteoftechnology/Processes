// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char child_text[] = "Hello";
	char parent_text[] = "Goodbye";
	int child = fork();
	if (child < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (child == 0) {
		printf("\n\n%s\n\n", child_text);
	} else {
		int wc = waitpid(child, NULL, 0);
		printf("\n\n%s\n\n", parent_text);
	}
	return 0;
}
