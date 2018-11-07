// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  // Your code here
  int x = 42;

  pid_t pid;
  pid = fork();
  if (pid < 0) {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (pid == 0) {
    int *ptr_child = &x;
    *ptr_child = 55;
    printf("X Child: %d\n", x);
  } else {
    wait(NULL);
    int *ptr_parent = &x;
    *ptr_parent = 77;
    printf("X Parent: %d\n", x);
  }
    printf("X Main: %d\n", x);
    return 0;
}
