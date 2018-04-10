// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  int cp = fork();
  if (cp < 0)
  {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  }
  else if (cp == 0)
  {
    printf("Hello (pid: %d) %d \n", (int)getpid(), cp);
  }
  else
  {
    waitpid(cp, NULL, 0);
    printf("Goodbye (pid: %d) %d \n", (int)getpid(), cp);
  }
  return 0;
}
