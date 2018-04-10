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

// int main()
// {
//   int val;
//   val = fork();

//   printf("%d\n", (int) getpid());
//   printf("%d\n", val);
// }

int main(int argc, char *argv[])
{
  int x = 100;
  printf("main value of x is: %d\n", x);
  printf("(pid: %d)\n", getpid());
  int cp = fork();

  if (cp < 0)
  {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  }
  else if (cp == 0)
  {
    x++; // 101
    printf("Child (pid: %d) with an x value of: %d\n", getpid(), x);
  }
  else
  {
    x--; // 99
    printf("Parent (pid: %d)with an x value of: %d\n", getpid(), x);
  }

  return 0;
}
