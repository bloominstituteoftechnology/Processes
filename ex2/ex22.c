// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int c;

  fp = fopen("file.txt","r");
  while(1) {
    c = fgetc(fp);
    if( feof(fp) ) { 
      break ;
    }
    printf("%c", c);
  }
  printf("\n");

  c = fork();

  if (c < 0) {    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (c == 0) {    // child process satisfies this branch
      printf("child x is %c, (pid: %d) \n", c, (int) getpid());
  } else {
      printf("hello, parent here (pid: %d) of child %c\n", (int) getpid(), c);
  }

  fclose(fp);

  return(0);
}
