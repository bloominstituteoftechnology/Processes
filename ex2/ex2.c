// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  // Your code here
  FILE *fp;
  fp = fopen("text.txt", "w");
  int x = fork();

  if (x < 0) {
    fprintf(stderr, "err\n");
    exit(1);
  }
  else if (x == 0) {
    /* char *child = "the child string\n"; */
    /* fwrite(child, 1, strlen(child), fp); */
    fprintf(fp, "%s", "child");
  }
  else {
    /* char *parent = "the parent string\n"; */
    /* fwrite(parent, 1, strlen(parent), fp); */
    fprintf(fp, "%s", "parent");
  }
  fclose(fp);
  return 0;
}
