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
    int fd1[2];
    pid_t pid;
    char inbuf[MSGSIZE];

    if(pipe(fd1) == -1){
      printf("Pipe failed.");
      return 1;
    }

    pid = fork();

    if(pid < 0){
      printf("Fork failed.\n");
      exit(1);
    }else if(pid == 0){
      close(fd1[0]); //close reading end of pipe
      write(fd1[1], msg1, MSGSIZE);
      write(fd1[1], msg2, MSGSIZE);
      write(fd1[1], msg3, MSGSIZE);
      close(fd1[1]);
    }else{
      close(fd1[1]);
      for(int i = 0; i < 3; i++) {
        read(fd1[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
      }
      close(fd1[0]);
    }

    return 0;
}
