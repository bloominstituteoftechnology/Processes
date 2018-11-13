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
    // Here we're making  a program to illustrate the pipe() system call an example:
    // As the instructions say we are making a program that forks a child and creates a shared pipe
    // between parent and child. Which is a connection from parent to child. So the output of the parent can become the input for the child etc.
    // One way communcation
    /*
    int pipe(int fds[2]);
    Parameters :
    fd[0] will be the fd(file descriptor) for the
    read end of pipe.
    fd[1] will be the fd for the write end of pipe.
    Returns : 0 on Success.
    -1 on error.
    */
    char inbuf[MSGSIZE];
    int p[2];
    if (pipe(p)<0){
      fprintf(stderr,"pipefailure");
      exit(1);
    } else {
      int child=fork();
      if (child == 0){
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
      } else {
        for (int i =0; i <3; i++){
          read(p[0], inbuf, MSGSIZE);
          printf("%s\n", inbuf);
        }
      }
    }

    return 0;
}
