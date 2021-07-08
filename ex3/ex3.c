// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	printf("hello world (pid: %d)\n", (int)getpid());

	pid_t pid = fork();

	if (pid == 0) {
		printf("Hello from Child, and my pid is %d!\n", getpid());
	}
	else {
		int wc = waitpid(pid, NULL, 0);
		printf("Hello from Parent, and my pid is %d!\n", getpid());
	}
    return 0;
}
