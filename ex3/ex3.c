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

  printf("main process - pid: %d \n\n", (int)getpid());
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "fork failure alert!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("hello\n\n");
  }
  else
  {
    int wait = waitpid(rc, NULL, 0);
    printf("goodbye\n\n");
  }
    return 0;
}
