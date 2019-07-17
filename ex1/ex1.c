// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here

    int x = 100;

    int rc = fork();

    if (rc < 0) {
    	printf("Fork failed...\n");
    } else if (rc == 0) {
    	// child returns 0 to fork...
    	printf("The value of x in child is %d.\n", x);

    	x = 101;

    } else {
    	// parent returns child's PID -> getpid()
    	printf("The value of x in parent is %d.\n", x);

    	x = 102;
    }

    printf("The final value of x is %d\n", x);

    return 0;
}
