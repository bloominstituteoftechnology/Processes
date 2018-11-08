// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


const int MAX_COUNT = 100;

void ChildProcess(void)
{
  int i;

  for (i = 1; i <= MAX_COUNT; i++){
    printf("   This line is from child, value = %d\n", i);
    printf("   *** Child process is done ***\n");}
  return;
}

void ParentProcess(void)
{
  int i;
  for (i = 1; i <= MAX_COUNT; i++){
    printf("This line is from parent, value = %d\n", i);
    printf("*** Parent is done ***\n");}
  return;
}

int main(void)
{
  // Your code here
  int x = 100;
  int rc = fork();
  printf("value of x >> %d\n", x);
  if(rc < 0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0){
    printf("hello, child here (pid: %d) \n", (int) getpid());
    ChildProcess();
  } else {
    printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    ParentProcess();
  }

  return 0;
}

