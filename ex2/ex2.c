// Write a program that opens the text.txt  file (with the `open()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `open()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h> // <~~~ for open()

int main(int argc, char* argv[])
{
  // Your code here

  int xmas = open("test.txt", O_RDONLY);
  printf ("%d", xmas);


  // int rc = fork();
  // if (rc < 0) {    // fork failed; exit
  //   fprintf(stderr, "fork failed\n");
  //   exit(1);
  // } else if (rc == 0) {    // child process satisfies this branch
  //   printf("\nhello, child here (pid: %d) \n", (int) getpid());
  //   printf("The value of x in the child process is: %d\n", x);
  //   x = 12345;
  //   printf("The value of x in the child process has been changed: %d\n", x);
  // } else {
  //   printf("\nhello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
  //   printf("The value of x in the parent process is: %d\n", x);
  //   x = 54321;
  //   printf("The value of x in the parent process has been changed: %d\n", x);
  // }
  // printf("Now what is the value of x? %d\n", x);

  close();
  return 0;
}
