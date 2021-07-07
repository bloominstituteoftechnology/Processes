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
  char inbuf[MSGSIZE];
  int file[2];
  int piper = pipe(file);
  int child = fork();
  if (piper < 0)
  {
    perror("pipe failed\n");
    exit(1);
  }
  if (child < 0)
  {
    perror("fork failed\n");
    exit(1);
  }
  if (child == 0)
  {
    printf("\nChild sending the following messages:\n");
    write(file[1], msg1, MSGSIZE);
    write(file[1], msg2, MSGSIZE);
    write(file[1], msg3, MSGSIZE);
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      read(file[0], inbuf, MSGSIZE);
      printf("%s\n", inbuf);
    }
  }

  return 0;
}
