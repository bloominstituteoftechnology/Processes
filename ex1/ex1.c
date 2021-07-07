// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    
    int x = 100;
    int y = fork();

    //if y = 0 then I'm in the child process
    if (y == 0){
            //changes to x in the child has a different value then changes made in the parent
        printf("Child is x = %d\n", ++x);
       //if y is positive, most likely the pid of the value, then print the parent value
    } else{
        printf("Parent is x = %d\n", --x);
    }

    return 0;
}
