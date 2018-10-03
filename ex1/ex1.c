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
      fprintf(stderr, "Fork failed!\n");
      exit(1);
    } else if (rc == 0)
    {
      x = x * 2;
      printf("%d is the child and %d is its pid.\n", x, (int) getpid());
    } else
    {
      x = x * 3;
      printf("%d is the parent and %d is the pid of %d.\n", x, (int) getpid(), rc);
    }

    return 0;
}
