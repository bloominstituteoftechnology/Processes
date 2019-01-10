// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  // Your code here
  int x = fork();
  if (x < 0) {
    fprintf(stderr, "err\n");
    exit(1);
  }
  else if (x == 0) {
    printf("hello");
  }
  else {
    printf("goodbye");
  }
  return 0;
}
