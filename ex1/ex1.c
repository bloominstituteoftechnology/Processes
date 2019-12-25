// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   int pi_d;
   int x = 100;
   pi_d = fork();
   if(pi_d == 0){
       printf("Child Process B:\npid :%d\nppid:%d\n", getpid(),getpid());
   }
   if(pi_d > 0){
       x = fork();
       if(x > 0){
           printf("\nParent Process:\npid:%d\nnid :%d\n", getpid(),getpid());
       }
       else if(x == 0){
           printf("Child Process A:\npid :%d\nppid :%d\n", getpid(),getpid());
       }
   }
}
