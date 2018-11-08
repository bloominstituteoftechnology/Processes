// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int x = 100;
  printf("Parent x is %d before fork, (pid: %d)\n", x, (int) getpid());
  
  int new;
  new = fork();

  printf("Logging after fork, (pid: %d)\n", (int) getpid());

  if (new < 0) {    // fork failed; exit
      fprintf(stderr, "fork failed\n");
      exit(1);
  } else if (new == 0) {    // child process satisfies this branch
      printf("child x is %d, (pid: %d) \n", x, (int) getpid());
  } else {
      printf("hello, parent here (pid: %d) of child\n", (int) getpid());
  }

  return 0;
}
