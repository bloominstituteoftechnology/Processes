// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  printf("Main process (pid: %d)\n", (int)getpid());
  printf("Forking child process...\n");
  int child = fork();

  if (child < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (child == 0)
  {
    printf("Hello (from child %d)\n", (int)getpid());
  }
  else
  {
    int w = waitpid(child, NULL, 0);
    if (w != -1)
      printf("Goodbye (from parent %d of child %d)\n", (int)getpid(), child);
  }

  return 0;
}
