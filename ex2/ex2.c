// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
  FILE * fileprint;

  fileprint = fopen ("text.txt", "w+");
   int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
      fprintf(fileprint, "%s", "I am the child\n");
    } else {
      fprintf(fileprint, "%s", "I am the parent\n");
    }

  fprintf(fileprint, "%s", "This is the main\n");
  fclose(fileprint);
    
  return 0;
}
