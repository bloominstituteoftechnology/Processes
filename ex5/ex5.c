// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

// - [Dig Deeper: linux die's pipe explanation](https://linux.die.net/man/2/pipe)
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
  char buffer[MSGSIZE]; // sets up a buffer of 16 bytes
  int p[2]; // sets up pipe, returns 2 file descriptors for each end of pipe

  // PIPE FAIL CHECK
  if (pipe(p) < 0) { 
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }

  // FORK
  int rc = fork();

  // FORK FAIL CHECK
  if (rc < 0) { 
    fprintf(stderr, "fork failed\n");
    exit(1);
  }

  // CHILD - reads messages from parent
  if (rc == 0) {
    printf("From child, PID: %d, PPID: %d\n", getpid(), getppid());
    for (int i=0; i<3; i++) {
      read(p[0], buffer, MSGSIZE); // p[0] is the read end by default
      printf("%s \n", buffer);
    }
  }
  // PARENT - write messages for child
  else {
    printf("From parent: PID: %d, PPID: %d\n", getpid(), rc);
    write(p[1], msg1, MSGSIZE); // p[1] is the write end by default
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
  }

  return 0;
}
