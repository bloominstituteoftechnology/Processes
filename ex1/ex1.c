// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
  int x = 100;
  printf("My main process has pid: %d, and x = %d\n\n", (int)getpid(), x);
  int rc = fork();

  // this is where the child forks off
  if (rc < 0)
  {  
    fprintf(stderr, "fork failure alert\n");
    exit(1);
  } 

  else if (rc == 0)
  {
    printf("The child process has pid: %d, and x = %d\n\n", (int)getpid(), (x+5));
  }

  else 
  {
    printf("The parent process has pid: %d, its child has pid: %d, and x = %d\n\n", (int)getpid(), rc, (x-1));
  } 
    return 0;
}
