// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
//Answer: It seems like the variable will always end up as the parents value at the end of the program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("I'm the parent process, and my pid is %d!\n", getpid());

	int x = 100;
	pid_t pid = fork();

	if (pid == 0) {
		printf("I'm the child process, and my pid is %d!\n", getpid());
		x += 1;
		printf("x:%d for child\n", x);
		exit(0);
	}
	else {
		x += 10;
		printf("x:%d for parent\n", x);
	}
	printf("I'm the parent again, and I just spawned child %d!\n", pid);

	printf("x:%d out of if\n", x);

	printf("WAT: pid: %d\n", getpid());

	return 0;
}
