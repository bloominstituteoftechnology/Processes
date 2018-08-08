// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here

int x = 0;
     x = 100;
    printf("Variable x = %d\n",x);
     int rc = fork();
    // start of child process
    if (rc < 0) {    // fork failed;
        fprintf(stderr, "fork failed\n");
        exit(1); //exit
    } else if (rc == 0) {    // child process satisfies this branch
        printf("Hello, child \n");
        printf("Child x = %d \n",x);
        printf("Child second timex = %d \n",x);
        x = 10;
        printf("Child x = %d \n",x);
    } else {
        printf("Hello, parent of child\n");
        printf("Parent x = %d \n",x);
        x = 50;
        printf("Parent x = %d \n",x);
    }
    printf("Variable x = %d (pid: %d) \n",x, (int) getpid());
    return 0;
}

//EXPECTED OUTPUT

// Variable x = 100
// Hello, parent of child
// Hello, child
// Parent x = 100
// Child x = 100
// Parent x = 50
// Child second timex = 100
// Variable x = 50 (pid: 5130)
// Child x = 10
// Variable x = 10 (pid: 5131)