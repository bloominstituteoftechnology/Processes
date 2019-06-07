// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?
/*
1. Why do you think there are so many variants of the same basic call?
  From the best of my understanding here: https://www.geeksforgeeks.org/exec-family-of-functions-in-c/ ...
  The differences of the exec family of commands are all related to what arguments they accept when you exec the program. 
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  char *args[] = {"/mnt/c/Users/mdaga/dev/lambda_school/Processes/ex3/ex3", NULL};
  // Your code here
  int main_fork = fork();
  if (main_fork)
  {
    execvp(args[0], args);
    printf("Print me.");
  }
  return 0;
}