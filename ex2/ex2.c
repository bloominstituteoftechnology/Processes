// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp = fopen("text.txt", "w+");
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
    printf("Child process (pid: %d), writing to file fp...\n", (int)getpid());
    fputs("This is a string written by the child process.\n", fp);
  }
  else
  {
    printf("Parent process (pid: %d) of child %d, writing to file fp...\n", (int)getpid(), child);
    fputs("This is a string written by the parent process.\n", fp);
  }

  fclose(fp);
  return 0;
}
