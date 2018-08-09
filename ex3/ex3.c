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
//    printf("this is the parent process - pid: %d, and the child process is pid: %d \n\n", (int)getpid(), rc);
    int wait = waitpid(rc, NULL, 0);
// I tried doing this exactly as discussed in class but it kept giving me unused variable warnings. Which I can understand because we never actually use this variable anywhere. It compiles, though, and the child prints first.
    printf("goodbye\n\n");
  }
    return 0;
}


