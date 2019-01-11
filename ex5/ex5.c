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
    //I the read
    close(p[0]);
    //I know have the child start sending messages to the parent
    printf("child sending messages\n");
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
    //I close write
    close(p[1]);
  } else {
    //I close write
    close(p[1]);
    //I loop through all the piped information from child
    //and I print that out in the terminal
    for (int i = 0; i < 3; i++) {
      read(p[0], inbuf, MSGSIZE);
      printf("parent prints: %s\n", inbuf);
    }
    //I close read
    close(p[0]);
  }
  return 0;
}