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

printf("Main process: %d \n", (int)getpid());
  int rc = fork();
   if (rc < 0)
  {
    fprintf(stderr, "fork failure alert!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Hello (from child %d)\n", (int)getpid());
  }
  else
  {
    int wait = waitpid(rc, NULL, 0);
    if (wait != -1)
   printf("Goodbye (from parent %d of child %d)\n", (int)getpid(), rc);
  }
    return 0;
}
