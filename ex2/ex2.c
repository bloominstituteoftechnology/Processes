// Write a program that opens the text.txt file (with the `fopen()`
// system call) located in this directory and then calls `fork()` to
// create a new process.

/*
  Can both the child and parent access the file descriptor returned by `fopen()`?

  What happens when they are written to the file concurrently?
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  // FILE* fp;
  int cp = fork();
  FILE * file; // file pointer
  file = fopen("text.tx", "w+"); // open file

  if (cp < 0)
  {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  }
  else if (cp == 0)
  {
    printf("Child-pid: %d \n", (int) getpid());
    FILE *file = fopen("text.tx", "a");
    fprintf(file, "%s\n", "This line came from the child process.");
    fclose(file);
  }
  else
  {
    waitpid(cp, NULL, 0);
    FILE *file = fopen("text.tx", "a");
    printf("Parent-pid: %d\n", (int) getpid());
    fprintf(file, "%s\n", "This content came from the parent process.");
    fclose(file);
  }
  return 0;
}
