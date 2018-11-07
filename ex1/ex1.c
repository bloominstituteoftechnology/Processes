// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x;
    pid_t pid;

    x = 25;

    pid = fork();

    if(pid < 0){
      printf("Fork failed.\n");
      exit(1);
    } else if(pid == 0) {
      printf("\nThe value of x in the child is: %d.\n\n", x);
    }else{
      x = 100;
      printf("\nThe parent has changed the value to %d.\n\n", x);
    }

    return 0;
}
