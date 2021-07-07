// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
  int rc = fork();

  if (rc < 0)
  { 
    fprintf(stderr, "fork failure alert!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    execl("/bin/ls", "ls", NULL);
  }
  else
  {
    int wc = waitpid(rc, NULL, 0);
    printf("Parent process - pid: %d\n", (int)getpid());
  }
  
    return 0;
}