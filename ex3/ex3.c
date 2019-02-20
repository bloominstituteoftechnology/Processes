// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  int hello_fork = fork();

  if (hello_fork)
  {
    return printf("hello");
  }

  printf("goodbye");
  return 0;
}
