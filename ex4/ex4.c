// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others.

/*
  Why do you think there are so many variants of the same basic call?

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int cp = fork();
  if (cp < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (cp == 0)
  {
    char *command[] = { "ls", "-l", NULL };
    execvp ("ls", command);
  }
  else // this only runs b/c we used fork
  {
    // try diff versions of exec() in this block
    waitpid(cp, NULL, 0);
    printf("Parent process (pid: %d) of child process. %d\n", (int) getpid(), cp);
  }
  return 0;
}
