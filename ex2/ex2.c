// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  // Your code here 
  FILE *fp = fopen("text.txt", "w");
  int rc = fork();
  
  if(rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if(rc == 0)
  {
    fprintf(fp, "Hello from child.\n");
    printf("Hello from child.\n");
  }
  else
  {
    fprintf(fp, "Hello from parent.\n");
    printf("Hello from parent\n");
  }
  fclose(fp);
  
  return 0;
}
