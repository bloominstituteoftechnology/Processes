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
    int pipefd[2]; 
    char buf[MSGSIZE]; 

  // create pipe
  if (pipe(pipefd) < 0)
  {
    fprintf(stderr, "pipe failure alert!\n");
    exit(1);
  }

  // fork me
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failure alert!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    close(pipefd[0]); 
    write(pipefd[1], msg1, MSGSIZE);
    write(pipefd[1], msg2, MSGSIZE);
    write(pipefd[1], msg3, MSGSIZE);
    close(pipefd[1]); 
  }
  else
  {
    int wait = waitpid(rc, NULL, 0); 
    close(pipefd[1]); 
    int i;
    for (i = 0; i < 3; i++)
    {
      read(pipefd[0], buf, MSGSIZE);
      printf(" %s\n", buf);
    } 
  } 
    return 0;
}

