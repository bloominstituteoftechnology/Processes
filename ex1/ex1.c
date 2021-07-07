// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


//after the variable is changed in the parent call, the child takes on the parent variable amount.
//when the child variable is changed, it only affects the child process, subsequent parent print 
//command reveals no change to variable.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("parent fork x value is %d\n", x);
    x=50;
    printf("parent fork x value(changed) is %d\n", x);
    int child_fork = fork();
    
    if (child_fork == 0) {
      printf("child fork x value is %d\n", x);
      x= 25;
      printf("child fork x value(changed) is %d\n", x);
      printf("final child fork x value(changed) is %d and process id is: %d\n", x, (int)getpid());
        }
        else {
          int wc = waitpid(child_fork, NULL, 0); // `waitpid` call added here
          printf("hello, parent here, x value is %d - (pid: %d) of child %d\n", x, (int)getpid(), child_fork);
        }
   

        return 0;
}
