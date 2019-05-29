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
  int x = fork();
  int fd1[2];
  int fd2[2];

  if (pipe(fd1)==-1) {
    fprintf(stderr, "pipe failed");
    return 1;
  }
  else if (pipe(fd2)==-1) {
    fprintf(stderr, "pipe failed");
    return 1;    
  }
  
  if(x == 0) {
    close(fd1[1]);
    char concat_str[100];
    read(fd1[0], concat_str, 100);
    int k = strlen(concat_str);
    int i;
    for(i=0; i<strlen(fixed_str); i++)
      concat_str[k++] = fixed_str[i];    
  }
  
  else {
    close(fd2[1]);
    char concat_str[100];
    read(fd1[0], concat_str, 100);
    int k = strlen(concat_str);
    int i;
    for(i=0; i<strlen(fixed_str); i++)
      concat_str[k++] = fixed_str[i];
  }
  return 0;
}
