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
  int status;
  char *args[2];

  args[0] = "/bin/ls";
  args[1] = NULL;
  int y = fork();
  //char *const envp[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};


  // with execv the first argument passed in represents the file you wish to execute, and the second argument is an array of null-terminated strings that represent the appropriate arguments to the file as specified

// The execle function is most commonly used to overlay a process image that has been created by a call to the fork function.

//it appears there is different function call types to give you more flexability. For example the execle functions allow the caller to specify the environment of the executed program while execv provides an array of pointers to null-terminated strings that represent the argument list available to the new program

  if (y == 0) {
    execv(args[0], args);
    // execl("/bin/ls", "ls", NULL);
    // execle("/bin/ls", "ls", NULL);
  } else {
    wait(&status);
  }
  return 0;
}

