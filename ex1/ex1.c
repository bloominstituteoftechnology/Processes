// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
//
// The value of the variable is 100. When changing the value of the variable in the Parent
// and child, it changes to the value of the what is defined and doesn't interfere with the
// other value changes of the same variable.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    pid_t pid = fork();

    if (pid == 0) {
      x = 10;
      printf("Child! X is %d\n", x);
    } else {
      x = 20;
      printf("Parent! X is %d\n", x);
    }

    return 0;
}
