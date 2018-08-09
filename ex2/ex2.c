// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  FILE *text_file;
  text_file = fopen("text.txt", "r+");
  int forked = fork();

  if (forked < 0)
  { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (forked == 0)
  {
    // child process satisfies this branch
    fprintf(text_file, "%s", "Look at me, I'm writing text into a file. I am a child.\n");
  }
  else
  {
    fprintf(text_file, "%s", "Look at me, I'm writing text into a file. I am a parent.\n");
  }
  fclose(text_file);

  return 0;
}