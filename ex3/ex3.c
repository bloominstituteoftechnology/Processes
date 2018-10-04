// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "Fork failed!\n");
    exit(1);
  } else if (rc == 0) {
    printf("This is the child.\n");
  } else {
    wait(NULL);
    printf("This is the parent.\n");
  }
  return 0;
}
