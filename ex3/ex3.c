// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  int rc = fork();
  int waitProcessID = waitpid(rc, NULL, 0);
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Child process \t Hello!! \n");
  }
  else
  {
    printf("Parent process \t Goodbye \n");
  }

  return 0;
}

// Before waitpid on rc is put
// Parent process   Goodbye
// Child process    Hello!!

//  After the made to wait on child process to finish
// Child process    Hello!!
// Parent process   Goodbye