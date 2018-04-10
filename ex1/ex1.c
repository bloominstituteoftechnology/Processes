// Write a program that calls `fork()`. Before calling `fork()`,
// have the main process access a variable (e.g., x) and set its
// value to something (e.g., 100).

/*
What value is the variable in the child process?

What happens to the variable when both the child and parent change the value of x?

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int x = 100;
  printf("main value of x is: %d\n", x);

  int childprocess = fork();

  if (childprocess < 0)
  {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  }
  else if (childprocess == 0)
  {
    x++;
    printf("Child (pid: %d) with an x value of: %d\n", (int) getpid(), x);
  }
  else
  {
    x--;
    printf("Parent (pid: %d)with an x value of: %d\n", (int) getpid(), x);
  }

  return 0;
}
