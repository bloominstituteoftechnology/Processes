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
  FILE * file; // file pointer
  file = fopen("text.tx", "w+"); // open file
  fprintf(file, "%s\n", "This is some file content.");
  fclose(file);

  int childprocess = fork();

  if (childprocess < 0) {
    fprintf(stderr, "Failed to create a child process\n");
    exit(1);
  } else if (childprocess == 0) {
    FILE *edit = fopen("text.tx", "a");
    printf("Child-pid: %d \n", (int) getpid());
    fprintf(edit, "%s\n", "This line came from the child process.");
    fclose(edit);
  } else {
    waitpid(childprocess, NULL, 0);
    FILE *edit = fopen("text.tx", "a");
    printf("Parent-pid: %d\n", (int) getpid());
    fprintf(edit, "%s\n", "This content came from the parent process.");
    fclose(edit);
  }
  return 0;
}
