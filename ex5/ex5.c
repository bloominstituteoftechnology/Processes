// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
  char buffer[MSGSIZE];
  int rwpipe[2], cpid;

  if (pipe(rwpipe) < 0)
  {
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }
  printf("Parent pid: %d\n", (int) getpid());

  if ((cpid = fork()) > 0)
  {
    printf("Begin writing to pipe from child process: %d\n", (int) getpid());

    write(rwpipe[1], msg1, MSGSIZE);
    write(rwpipe[1], msg2, MSGSIZE);
    write(rwpipe[1], msg3, MSGSIZE);
  }
  else
  {
    printf("Begin reading from pipe from parent process: %d\n", (int) getpid());
    for (int i = 0; i < 3; i++)
    {
      read(rwpipe[0], buffer, MSGSIZE);
      printf("(pid: %d): %s\n", (int) getpid(), buffer);
      printf("%s\n", buffer);
    }
  }

  return 0;
}
