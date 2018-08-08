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

    // ------------------------------------------------ child process starts executing here

    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, Im the child \n");
        printf("Child x = %d \n",x);
        printf("Child second time printf x = %d \n",x);
        x = 18;
    } else {
        printf("hello, Im the parent of child\n");
        printf("Parent x = %d \n",x);
        x = 90;
    }
    printf("Variable x = %d (pid: %d) \n",x, (int) getpid());
    return 0;
}
