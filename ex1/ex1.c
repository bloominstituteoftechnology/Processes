// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  // first set x to 100 I guess
  int x = 100;
  int rc = fork();
  if (rc == 0){
    printf(" the child is %d\n", x);
    //change value of x and see what happnes:
    x = 20;
    printf("Tada it's %d now\n", x);
  }
  else{
      printf(" Parnet is %d\n", x);
  }
  // leave return outside of if else branch
    return 0;
}
