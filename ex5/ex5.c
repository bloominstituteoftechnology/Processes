// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 30

char* msg1 = "I see a little";
char* msg2 = "silhouetto of a man.";
char* msg3 = "Scaramouche, Scaramouche,";
char* msg4 = "will you do the fandango?";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE];
    int p[2];
    if (pipe(p) < 0) {
      fprintf(stderr, "pipe failed\n");
      exit(1);
    }
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
    write(p[1], msg4, MSGSIZE);


    for (int i = 0; i <= 3; i++) {
      read(p[0], inbuf, MSGSIZE);
      printf("%s\n", inbuf);
  }
    return 0;
}
