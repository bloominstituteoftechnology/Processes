// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int x = 100;
  printf("Main process (pid: %d): x initialized to %d\n", (int)getpid(), x);
  printf("Forking child process...\n");
  int child = fork();

  if(child < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (child == 0)
  {
    printf("Child process (pid: %d): x is %d\n", (int)getpid(), x);
    printf("Child %d is changing the value of x to 75...\n", (int)getpid());
    x = 75;
    printf("Child process (pid: %d): x is %d\n", (int)getpid(), x);
  }
  else
  {
    printf("Parent process (pid: %d) of child %d: x is %d\n", (int)getpid(), child, x);
    printf("Parent %d is changing the value of x to 25...\n", (int)getpid());
    x = 25;
    printf("Parent process (pid: %d): x is %d\n", (int)getpid(), x);
  }

  return 0;
}
