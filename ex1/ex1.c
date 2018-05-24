// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Both Parent and Child values of x are printed, beginning with Parent.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("hello world (pid: %d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    // ---------------- child process executes
    if (rc < 0) {   // fork failed; exit
      fprintf(stderr, "fork failed, exiting\n");
      exit(1);
    } else if (rc == 0) {   // child process satisfies this branch
      x = 7;
      printf("hello, child here (pid: %d) with x value %d\n", (int)getpid(), x);
    } else {
      x = 3;
      printf("hello, parent here (pid: %d) with child x value %d\n", (int)getpid(), rc, x);
    }

    return 0;
}
