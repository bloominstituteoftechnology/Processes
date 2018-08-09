// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *fp;
  fp = fopen("text.txt", "w");
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "fork failed \n ");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Child process (pid: %d) \n", (int)getpid());
    char *childStr = "This is the day that the Lord has made\n";
    fwrite(childStr, 1, strlen(childStr), fp);
  }
  else
  {
    printf("Parent process here (pid:%d)\n", (int)getpid());
    char *parentStr = "We will rejoice and be glad in it \n";
    fwrite(parentStr, 1, strlen(parentStr), fp);
  }
  fclose(fp);
  return 0;
}
// Parent string was written first
// We will rejoice and be glad in it
// Child string is appended to the parent
// This is the day that the Lord has made