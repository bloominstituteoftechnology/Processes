// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;                            // have the main function access a variable and set it to 100
    int rc = fork();                       //child process begins

    // Structure inspired by the readme

    if (rc < 0) {                           //fork failed so exit
      fprintf(stderr, 'failed fork\n');
      exit(1);
    } else if (rc == 0) {                  // child process satisfies this branch, so do the thing
      x = 101;                               
      printf("(pid: %d), x is %d \n");      // PID = process identifier
    } else {
      int wc = waitpid(rc, NULL, 0);        // waitpid added - ensures child runs before parent
      x = 102;
      printf("(pid: %d) of child %d, x is %d\n", (int) getpid(), rc, x);
    }

    return 0;
}
