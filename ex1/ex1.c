// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
 int x = 100;//Program initiates a variable, x, with the value of 100
 printf("hello world(pid: %d)\n", (int)getpid());//pid is a process identifer

 int rc = fork();//fork is a copy of the original
//The fork call is then made, creating a child process

 if (rc < 0) {
     fprintf(stderr, "fork failed\n");
      exit(1);
  //error message 
  //If the result of the fork call is less than 0, it means that the fork failed
//In the event of fork failure, program prints ‘fork failed’ to stderr
      }else if (rc == 0 ) {

          printf("hello, I am child (pid: %d) and x  is: %d\n", (int) getpid(), x);
          x++;
          printf("child again, x is now: %d\n", x);
      }else{
          printf("hello, I am parent of %d(pid:%d)and x is: %d\n", rc,(int) getpid(), x);
          x--;
          printf("parent again, x is now: %d\n", x);
      }
      //If the value of rc is 0, the process handling the program is the child process
//Child process changes the value of x to 50
//Child process then prints out its pid number and the value of x”
      return 0;
    
}
