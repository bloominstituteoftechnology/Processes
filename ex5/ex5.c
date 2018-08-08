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
    // Your code here
  // I relied heavily on the example here: https://linux.die.net/man/2/pipe  
  int pipefd[2]; //create pipe file descriptor array - read/write
  char buf[MSGSIZE]; //create buffer for input

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
    close(pipefd[0]); //close unused end of pipe - read end
    write(pipefd[1], msg1, MSGSIZE);
    write(pipefd[1], msg2, MSGSIZE);
    write(pipefd[1], msg3, MSGSIZE);
    close(pipefd[1]); //done with the writing
  }
  else
  {
    int wait = waitpid(rc, NULL, 0); //make sure the child writes first
    close(pipefd[1]); //close unused end of pipe - write end
    int i; //kept getting error messages about C99 so I declared this first
    for (i = 0; i < 3; i++)
    {
      read(pipefd[0], buf, MSGSIZE);
      printf(" %s\n", buf);
    } //originally just had lines 52-53 but it only printed the first message - obv need a for loop here!
  } 
    return 0;
}
