// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// int main(void)
// {
//   int status;
//   char *args[2];

//   args[0] = "/bin/ls";
//   args[1] = NULL;
//   int y = fork();
 
//   if (y == 0) {
//     execv(args[0], args);
//   } else {
//     wait(&status);
//   }  

//     return 0;
// }

int main(int argc, char* argv[])
{
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("child here\n");
    execlp("ls", "ls", "-l", NULL);
  } else {
    int wc = waitpid(rc, NULL, 0);
    printf("parent here\n");
  }
  return 0;
}