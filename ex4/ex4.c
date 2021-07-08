// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	int ret;
	char *cmd[] = { "ls", "-l", (char *)0 };
	if (pid == 0) {
		ret = execl("/bin/ls", "ls", "-l", (char *)0);
	}
	else {
		ret = execv("/bin/ls", cmd);
	}

	return 0;
}
