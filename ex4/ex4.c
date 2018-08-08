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
  printf("Main process (pid: %d)\n", (int)getpid());
  printf("Forking child process...\n");
  int child = fork();

  if (child < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (child == 0)
  {
    printf("Child process (pid: %d)\n", (int)getpid());
    printf("Transforming child process into list command...\n");
    
    /*
    // Using execl(): int execl(const char *path, const char *arg, ...);
    char *path = "/bin/ls";
    char *arg0 = "ls";
    char *arg1 = "-a";
    char *arg2 = NULL;
    execl(path, arg0, arg1, arg2);
    printf("Sanity check. This should not print.");
    */

    /*
    // Using execlp(): int execlp(const char *file, const char *arg, ...);
    char *filename = "ls";
    char *arg0 = "ls";
    char *arg1 = "-a";
    char *arg2 = NULL;
    execlp(filename, arg0, arg1, arg2);
    printf("Sanity check. This should not print.");
    */

    /*
    // Using execv(): int execv(const char *path, char *const argv[]);
    char *path = "/bin/ls";
    char *myargs[3];
    myargs[0] = "ls";
    myargs[1] = "-a";
    myargs[2] = NULL;
    execv(path, myargs);
    printf("Sanity check. This should not print.");
    */

    // Using execvp(): int execvp(const char *file, char *const argv[]);
    char *myargs[3];
    myargs[0] = "ls";
    myargs[1] = "-a";
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
    printf("Sanity check. This should not print.");
  }
  else
  {
    printf("Parent process (pid: %d) of child %d\n", (int)getpid(), child);
  }

  return 0;
}
