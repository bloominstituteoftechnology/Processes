// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int process = getpid();
  printf("Hello world - process id = %d\n", process);
  int rc = fork();
  if(rc < 0) {
  	fprintf(stderr, "fork failed\n");
  	exit(1);
  } else if(rc == 0) {
  	printf("hello, child process here - process id = %d\n", (int) getpid());
  } else {
  	printf("hello parent process  of child here - parent process id = %d\n, child process id = %d\n", (int) getpid(), rc);
  }


  return 0;
}