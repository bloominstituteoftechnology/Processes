// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  int childprocess = fork();
  if (childprocess < 0)
  {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  }
  else if (childprocess == 0)
  {
    printf("Hello (pid: %d) %d \n", (int)getpid(), childprocess);
  }
  else
  {
    waitpid(childprocess, NULL, 0);
    printf("Goodbye (pid: %d) %d \n", (int)getpid(), childprocess);
  }
  return 0;
}
