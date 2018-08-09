// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  // Your code here
  int status;
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed \n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello, child process here\n");
  } else {
      // Still don't understand this
      while (waitpid(rc, &status, WNOHANG) == 0) {
        sleep(1);
      }
    printf("Bye Felica!\n");
  }

  return 0;
}
