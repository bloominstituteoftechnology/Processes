// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100).

/* 
1. What value is the variable in the child process?
  The value of the variable (x) in the child process is copied from the parent process.
2. What happens to the variable when both the child and parent change the value of x?
  Both values change accordingly. The child process does not effect the parent process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  int x = 100;
  int new_fork = fork();

  if (new_fork)
  {
    x = 99;
    return printf("Within the child process, the value of x is: %d\nnew_fork equates to %d\n", x, new_fork);
  }
  else
  {
    printf("Within the parent process, the value of x is: %d\nnew_fork equates to %d\n", x, new_fork);
    wait(NULL);
    x = 91;
    printf("Within the parent process, the x value is now: %d\nnew_fork equates to %d\n", x, new_fork);
  };

  return 0;
}
