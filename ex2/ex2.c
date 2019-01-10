// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
//
// The child does have access to the file and both the parent and child do
// write to the file without overwritting.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
  FILE *fp = fopen("text.txt", "w");
  pid_t rc = fork();

  if(rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if(rc == 0)
  {
    fputs("Hello from child.\n", fp);
    // fprintf(fp, "%s %s %s %s", "Hello", "from", "child.");

  }
  else
  {
    fputs("Hello from parent.\n", fp);
  }
  fclose(fp);

  return 0;



    return 0;
}
