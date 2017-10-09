// Write a program that opens the text.txt file (with the `open()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `open()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h> // <~~~ for open()

int main(int argc, char* argv[])
{
  int xmas = open("test.txt", O_RDONLY);
  printf ("%d\n", xmas); // <~~~ number used to refer to file?
// ----------------------------------------------- KIDS SAY THE DARNDEST THINGS!
  int rc = fork();
  if (rc < 0) {    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {    // child process satisfies this branch
    printf ("CHILD:  %d\n", xmas);
  } else {
    printf ("PARENT: %d\n", xmas);
  }
  printf("UNCONDITIONAL: %d\n", xmas);

  return 0;
}
