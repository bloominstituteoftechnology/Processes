// Write a program that calls `fork()`. Before calling `fork()`, have the main
// process access a variable (e.g., x) and set its value to something (e.g.,
// 100). What value is the variable in the child process? What happens to the
// variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Your code here

  int x = 1234;
  int child = fork();
  printf("1 child: %d The variable: %d\n", (int)getpid(), x);
  if (child < 0) {  // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (child == 0) {  // child process satisfies this branch
    int x = 5432;
    printf("2 Child PID: %d variable x: %d\n", (int)getpid(), x);
  } else {
    x--;
    printf("3 hello, parent here (pid: %d) of child %d, The variable: %d\n", (int)getpid(), child, x);
  }
  return 0;
}
