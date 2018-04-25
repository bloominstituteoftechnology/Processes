// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    printf("Hello world (pid: %d)\n", (int) getpid());

    int child = fork();

    if (child < 0) {
      fprintf(stderr, "fork failed...\n");
      exit(1);
    } else if (child == 0) {
      printf("Hello, I am child (pid: %d) and x is %d\n", (int) getpid(), x);
      x++;
      printf("Hello, child here, x is now %d\n", x);
    } else {
      printf("Hello, I am parent of %d (pid: %d) and x is %d\n", child, (int) getpid(), x);
      x--;
      printf("Hello, parent here, x is now %d\n", x);
    }

    return 0;
}
