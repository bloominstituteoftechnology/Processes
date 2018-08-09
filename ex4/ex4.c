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
  // printf("(pid:%d)\n", (int)getpid());
  int rc = fork();
  char *const envp[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};

  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // printf("Child process");
    execle("/bin/ls", "ls", "-l", NULL, envp);
    printf("Return unexpected. It must be an execle() error.n");
  }
  else
  {
    // printf("Parent process");
  }

  return 0;
}
