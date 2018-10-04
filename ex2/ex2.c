// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
  FILE *file_pointer = fopen("text.txt", "w");
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "Fork failed!\n");
    exit(1);
  } else if (rc == 0) {
    char *child = "This is the child.\n";
    fwrite(child, sizeof(char), strlen(child), file_pointer);
  } else {
    waitpid(rc, NULL, 0);
    char *parent = "This is the parent.\n";
    fwrite(parent, sizeof(char), strlen(parent), file_pointer);
  }
  fclose(file_pointer);
  return 0;
}
