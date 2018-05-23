// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// if the values are changed, then the change is only represented in the process that changed that value.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int k = 100;
    int rc = fork();
    if(rc < 0){
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if(rc == 0){
      k = 150;
      printf("k value: %d  from child process %d\n", k, (int) getpid());
    }
    else{
      printf("k value: %d  from parent process %d\n", k, (int) getpid());
    }
    return 0;
}
