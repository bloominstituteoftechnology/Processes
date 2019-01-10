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
    // Initilize the message size
    char inbuf[MSGSIZE];
    // Initilize the pipe and index
    int p[2], pid, nbytes;

    if (pipe(p) < 0) {
      exit(1);
    }

    // Write the pipe
    if ((pid = fork()) > 0) {
      write(p[1], msg1, MSGSIZE);
      write(p[1], msg2, MSGSIZE);
      write(p[1], msg3, MSGSIZE);

      // Don't hang the program
      wait(NULL);
    } else {
      // Read the pipe
      while ((nbytes = read(p[0], inbuf, MSGSIZE)) >0) {
        printf("% s\n", inbuf);
      }
      if (nbytes != 0) {
        exit(2);
      }
      printf("Finished reading\n");
    }

    return 0;
}
