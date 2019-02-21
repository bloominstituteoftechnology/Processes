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

int main(void)
{
  char inbuf[MSGSIZE];
  int p[2];

  if (pipe(p) < 0)
  {
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }

  printf("Before forking pid: %d\n", (int)getpid());
  printf("\np[0]: %d\n", p[0]);
  printf("p[1]: %d\n", p[1]);
  pid_t pid = fork();

  if (pid < 0)
  {
    exit(1);
  }
  else if (pid == 0)
  {
    printf("AFTER forking CHILD pid: %d\n", (int)getpid());

    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
  }
  else
  {
    waitpid(pid, NULL, 0);

    printf("AFTER forking PARENT pid: %d\n", (int)getpid());
    for (int i = 0; i < 3; i++)
    {
      read(p[0], inbuf, MSGSIZE);
      printf("Parent writes: %s\n", inbuf);
    }
  }

  return 0;
}
