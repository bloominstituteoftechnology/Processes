// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Your code here
  int x;
  x = 100;
  printf("hello world (pid: %d)\n", (int) getpid());
  // ------------------------------------------------ child process starts executing here
  int rc = fork();
  if (rc < 0) {    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {    // child process satisfies this branch
    printf("\nhello, child here (pid: %d) \n", (int) getpid());
    printf("The value of x in the child process is: %d\n", x);
    x = 12345;
    printf("The value of x in the child process has been changed: %d\n", x);
  } else {
    printf("\nhello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    printf("The value of x in the parent process is: %d\n", x);
    x = 54321;
    printf("The value of x in the parent process has been changed: %d\n", x);
  }
  printf("Now what is the value of x? %d\n", x);
  return 0;
}
