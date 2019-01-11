// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//when we call fork it sets its own copy so if I change the value of x in the child
//it will not effect the value of x in the parent.

int main(void)
{
   int x = 100;
   int y = fork();

   //if y = 0 then I'm in the child process
   if (y == 0){
		//notice that changes x in the child does not effect the parents
		//value of x, because they both have thier own copy
   	printf("Child is x = %d\n", ++x);
    //if y != 0 I'm in the parent process
   } else{
      printf("Parent is x = %d\n", --x);
   }

   return 0;
}