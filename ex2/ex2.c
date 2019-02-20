// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
/*
1. Can both the child and parent access the file descriptor returned by `fopen()`?
  Yes.
2. What happens when they are written to the file concurrently?
  Something strange happens and the parent process prints twice to the text file.
  > Hello world!
  > I'm writing from within the fork!Hello world!
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  // Your code here
  FILE *file;
  file = fopen("text.txt", "w+");

  int file_fork = fork();
  fprintf(file, "Hello world!");

  if (file_fork)
  {
    return fprintf(file, "\nI'm writing from within the fork!");
  }

  fclose(file);

  return 0;
}
