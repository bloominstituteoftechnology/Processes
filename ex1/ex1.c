// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?

// the value is the same in the child process
// What happens to the variable when both the child and parent change the value of x?

// They each retain their own copies it seems and their own variable gets changed respectively

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int hunter = 100;
    int child = fork();
    if (child == 0){
        
        printf("Hunter the Child is: %d\n", hunter);
        hunter +=1;
        printf("Hunter the Child changes to: %d\n", hunter);
    }
    else {
        
        printf("Hunter the Parent is: %d\n", hunter);
        hunter +=2;
        printf("Hunter the Parent changes to: %d\n", hunter);
    }

    return 0;
}
// returns:

//Hunter the Parent is: 102
//Hunter the Child is: 101