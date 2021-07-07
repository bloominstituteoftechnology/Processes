// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    
    //parent and child seem to return the same value when the main process accesses a variable. 
    int x = 100;
    int letsfork = fork();
    if (letsfork == 0){
        printf("Child is here and %d\n", x ); 
    } else {
        printf("Parent is here here and %d\n", x);
    }
    return 0;	   
}	



    // int letsfork = fork();
    // if (letsfork == 0){
    //     printf("Child is here" );
    // } else {
    //     printf("Parent is here");
    // }
    // return 0;	  