// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 
// What value is the variable in the child process? 
    // Same as the main process
// What happens to the variable when both the child and parent change the value of x? 
    // The Child alteres but the Parent remains unaltered. 

// Output:
// Parent: Getppid 1
// Child: Getpid 39
// Child: x unaltered = 10
// Child: x altered = 20
// Parent: x altered = 10


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x; 
    x = 10; //main process accessed a variable and set to 10

    int forked = fork();

    if (forked == 0) {
      printf("Child: Getpid %d\n", (int) getpid());
      printf("Child: x unaltered = %d\n", x); // child's x = 10

      x = 20; 
      printf("Child: x altered = %d\n", x); //altered to 20
    } else {
      printf("Parent: Getppid %d\n", (int) getppid());
      printf("Parent: x altered = %d\n", x); // unaltered by child's alteration
    }
    
    return 0;
}
