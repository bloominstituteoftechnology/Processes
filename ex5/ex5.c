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
  int p[2];
  pipe(p);

  if (fork() == 0){
    close(p[0]);
    printf("child sending messages\n");
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
    close(p[1]);
  } else {
    close(p[1]);
    for (int i = 0; i < 3; i++) {
      read(p[0], inbuf, MSGSIZE);
      printf("parent prints: %s\n", inbuf);
    }
    close(p[0]);
  }
  return 0;
}