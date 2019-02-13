// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

/* Interesting finding. The value in the child process will be the intial value that is called or the value that is 
inside's it's else if statement. If I tell the parent to change the value before it prints x, the x value will change 
but it will not change the child's x value because the else statement is not called. I actually thought it would have 
changed it but it was interesting to see that it did not.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // x = 20;
        printf("Child x:%d \n", x);
    }
    else
    {
        x = 200;
        printf("Parent x:%d \n", x);
    }
    return 0;
}
