// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
     int x = 100; // this creates the x variable as per the directions
    int rc = fork(); // this creates the rc variable and sets it equal to fork

    if (rc < 0) {    // if the value of rc is less than 0, then the fork fails; exits program
        fprintf(stderr, "fork failed\n"); //this outputs an error message that the fork failed
        exit(1);
    } else if (rc == 0) {
        // child process satisfies this branch
        x = x+5; //the value of x is increased by 5 if the child process works
        printf("the value of x for the child is %d \n", x); //prints the new value of x if the child process works
    } else {
        x = x*10; //if the parent process works, then the value of x is multiplied by 10
        printf("the value of x for the parent is %d \n", x); //if the parent process works then the new value of x is printed
    }
    return 0;

    return 0;
}
