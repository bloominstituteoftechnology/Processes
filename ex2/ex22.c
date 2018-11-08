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

  printf("Before Fork \n");
  int new;
  new = fork();
  printf("Parent Then Child Print After Fork, (pid: %d) \n", (int) getpid());

  if (new < 0) {    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (new == 0) {    // child process satisfies this branch
    fp = fopen("file.txt","r");
    while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
        break ;
      }
      printf("%c", c);
    }
    printf(" - Child Printed This, (pid: %d) \n", (int) getpid());
    fclose(fp);
  } else {
    fp = fopen("file.txt","r");
    while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
        break ;
      }
      printf("%c", c);
    }
    printf(" - Parent Printed This, (pid: %d)\n", (int) getpid());
    fclose(fp);
  }
  return(0);
}
