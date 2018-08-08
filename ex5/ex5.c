// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
  printf("Main process (pid: %d)\n", (int)getpid());
  char buffer[MSGSIZE];
  int rwPipe[2];

  printf("Establishing pipe...\n");
  if (pipe(rwPipe)){
    fprintf(stderr, "Pipe failed\n");
    exit(1);
  }

  printf("Forking child process...\n");
  int child = fork();

  if (child < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (child == 0)
  {
    printf("Child %d writing to pipe...\n", (int)getpid());
    write(rwPipe[1], msg1, MSGSIZE);
    write(rwPipe[1], msg2, MSGSIZE);
    write(rwPipe[1], msg3, MSGSIZE);
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      read(rwPipe[0], buffer, MSGSIZE);
      printf("Parent %d of child %d read from pipe: %s\n", (int)getpid(), child, buffer);
    }
  }

  return 0;
}
