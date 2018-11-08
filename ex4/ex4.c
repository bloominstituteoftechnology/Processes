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
  printf("Before Fork!\n");
  //execl("/bin/ls", "ls", NULL);

  pid_t process;
  process = fork();
  
  printf("Parent Then Child Print After Fork, (pid: %d) \n", (int) getpid());
  //execl("/bin/ls", "ls", NULL);

  if (process == 0) {
    printf("Hello from the child, (pid: %d) \n", (int) getpid());
    execl("/bin/ls", "ls", NULL);
  } else {
    printf("Parent is about to wait, (pid: %d) \n", (int) getpid());
    wait(NULL);
    printf("Goodbye from the parent, (pid: %d) \n", (int) getpid());
    execl("/bin/ls", "ls", NULL);
  }
  return 0;
}
