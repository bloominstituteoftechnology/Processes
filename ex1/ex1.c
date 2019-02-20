// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  // Your code here
  int x = 800;
  printf("Initial value %d\n", x);

  pid_t pid = fork();

  if (pid < 0)
  {
    exit(1);
  }
  if (pid == 0)
  {
    printf("value of x child process, (x:%d) (pid:%d)\n", x, getpid());
  }
  else
  {
    x = 100;
    printf("value of x parent process %d\n", x);
  }

  return 0;
}
