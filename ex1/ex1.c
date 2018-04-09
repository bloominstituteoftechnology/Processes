// Write a program that calls `fork()`. Before calling `fork()`,
// have the main process access a variable (e.g., x) and set its
// value to something (e.g., 100).

/*
What value is the variable in the child process?
  - The value is 101
What happens to the variable when both the child and parent change the value of x?
  - The variable is initially 100, and then the value is changed based on whatever
    code is run inside the process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int x = 100;
  int childprocess = fork();
  if (childprocess < 0) {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  } else if (childprocess == 0) {
    x++;
    printf("int x %d child (pid: %d) \n", x, (int) getpid());
  } else {
    x--;
    printf("int x %d parent (pid: %d)\n", x, (int) getpid());
  }

  return 0;
}
