// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
  // Your code here
  int x;

  x = 100;

  int rc = fork();
  char *val = "Child";

  if (rc < 0) { // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);      
  } else if (rc > 0) {
    int wc = waitpid(rc, NULL, 0);
    x--;
    val = "Parent";
  }
  x++;
  printf("%s: %i\n", val, x);

  return 0;
}
