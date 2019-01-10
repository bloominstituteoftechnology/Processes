#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid == 0) {
		printf("I'm the child!\n");
	} else {
		printf("Parent is about to wait!\n");
		wait(NULL);
		printf("I'm the parent!\n");
	}

	return 0;
}