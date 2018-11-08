#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
  char commandline[8192];

  while (printf("$ "), fgets(commandline, sizeof commandline, stdin) != NULL) {
    char *nl = strrchr(commandline, '\n');

		if (nl != NULL) {
			*nl = '\0';
		}

    pid_t pid = fork();

    if (pid == 0) {
      execlp(commandline, commandline, NULL);
      perror("exec");
      exit(1);
    } else {
      wait(NULL);
    }
  }

}