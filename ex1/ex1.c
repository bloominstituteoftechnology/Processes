// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int x = 100;
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Child process created (pid: %d) and (x:%d) \n", (int)getpid(), x);
    x++;
    printf("child again, x is now %d\n", x);
  }
  else
  {
    printf("Parent process here (pid: %d) of child (rc: %d)\n", (int)getpid(), rc);
    x--;
    printf("parent here again, x is now %d \n", x);
  }

  return 0;
}

// Parent process here (pid: 3447) of child (rc: 3448)
// Child process created (pid: 3448) and (x:100)
// The parent child processes are distinct working on their own copy of the variable x.
// parent here again, x is now 99
// child again, x is now 101