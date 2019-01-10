// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// The value is changed to 100 when parent process occurs.
// What happens to the variable when both the child and parent change the value of x?
// They create differecnt processes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    // variable
    int x = 50;
    int child = fork();

    if(child == 0) {
      printf("\nx value: %d", x);
    }else{
      x = 100;
      printf("\n value: %d", x); 
}
return 0;
}