// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
/*
to access a variable  is to read or assign the information inside the variable. to access a variable you simply type its name. 
*/

//What happens is that each variable is it changes for that position x is changed for the child and x is changed for the parent.  however x doesn't really change   example 

/*
here  is one of the outputs. 
x is : 100
x is : 722
x is : 100
x is : 122

so this is the before the change and after   722 is the parent 122 is the child.    intially it will be 100 but for the child it is also intially set at 100 even after the parent change.  the child doesn't recongize this change at all. 

https://repl.it/@codejoncode/Lambda-Excercise-1-Fork
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100; 
    int rc = fork();
    
    if(rc == 0){
      printf("x is : %d\n", x); 
      x = 122;
      printf("x is : %d\n", x); 
    } else{
      printf("x is : %d\n", x); 
      x = 722; 
      printf("x is : %d\n", x);  
    }


    return 0;
}