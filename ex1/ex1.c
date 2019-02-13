// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the y process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    //if this printf is below fork then it prints/runs before parent and child
    printf("The initial value of x is %d.\n", x); 
    int y = fork();

    if (y == 0) //this executes child
    {   
        x+=10;
        printf("Child is exuting this code, it's adding by 10, x is now %d.\n", x);
    }
    else if (y > 0) //this executes parent
    {
        x-=15;
        printf("Parent is exuting this code, it's subtracting by 15, x is now %d.\n", x);
    }
    else{ //this covers our bases in case of an error
        fprintf(stderr, "Fork Failed!\n");
        exit(1);
    }

    return 0;
}