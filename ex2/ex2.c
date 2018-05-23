// Write a program that opens the text.txt  file (with the `fopen()` system
// call) located in this directory and then calls `fork()` to create a new
// process. Can both the child and parent access the file descriptor returned by
// `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  // Your code here
  FILE* fp;
  fp = fopen("text.txt", "a+");
  int child = fork();
  if (child < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (child == 0) {
    fprintf(fp, "%s", "Child: Here's a thing.\n");
  } else {
    fprintf(fp, "%s", "Parent: Here's one more thing.\n");
  }
  fclose(fp);
  return 0;
}
