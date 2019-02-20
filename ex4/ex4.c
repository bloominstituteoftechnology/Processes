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
  // Your code here
  printf("Before forking pid: %d\n", (int)getpid());

  pid_t pid = fork();

  if (pid < 0)
  {
    exit(1);
  }
  else if (pid == 0)
  {
    printf("AFTER forking CHILD pid: %d\n", (int)getpid());

    char *myargs[2];

    myargs[0] = "/bin/ls";
    myargs[1] = NULL;

    execvp(myargs[0], myargs);

    printf("this should not be seen");
  }
  else
  {

    int wc = waitpid(pid, NULL, 0);
    printf("this should not be seen");
  }
  return 0;
}
