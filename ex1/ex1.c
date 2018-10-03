// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int n = 5;
    printf("Hello, world! (pid: %d)\n", (int) getpid());

    int rc = fork();

    if (rc < 0)
    {
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if (rc == 0)
    {
      printf("I am child (pid: %d) and x is: %d\n", (int) getpid(), n);
      n++;
      printf("Child process, n is now: %d\n", n);
    }
    else
    {
      printf("I am parent of %d (pid: %d) and n is: %d\n", rc, (int) getpid(), n);
      n--;
      printf("Parent process, n is now: %d\n", n);
    }

    return 0;
}
