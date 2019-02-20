// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100).
/* 
What value is the variable in the child process?
  1. The value of the variable (x) in the child process is copied from the parent process.
What happens to the variable when both the child and parent change the value of x?
  2. Both values change accordingly. The child process does not effect the parent process.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  // Your code here
  int x = 100;
  int new_fork = fork();
  if (x == 100)
  {
    printf("Within the child process, the value of x is: %d\n", x);
    printf("new_fork equates to %d\n", new_fork);
    x = 99;
  }
  x = 91;
  printf("Within the child process, the value of x is: %d\n", x);
  printf("new_fork equates to %d\n", new_fork);
  return 0;
}
