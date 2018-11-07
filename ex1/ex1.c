// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//mostly read the readme to understand this first one. 
int main(void)
{
   int x = 100; 

   int caller = fork(); 
    //the caller has to be above 0 to actual fork anything
    //if not then the fork fails.
   if(caller < 0){
       printf("Forked Failed \n");
    //if the caller is equal to 0 then the fork may happen.
    //this also means that the child is being called.
   }else if (caller == 0){
       printf("This is the Child (pid: %d) \n", (int) getpid());
       x++;
       printf("Child - x is now: %d\n", x);
    //if the caller is larger than 0 than the parent will be called.
   } else{
       printf("This is the Parent (pid: %d) of child %d\n", (int) getpid(), caller);
       x--;
       printf("Parent - x is now: %d\n", x);
   }
    return 0;
}
