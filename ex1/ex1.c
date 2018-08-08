// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 15;
	int rc = fork();

	if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    }  else if (rc == 0) {
    		x = 25;
        printf("Child is: x=%i\n", x);
    } else { 
    	x = 90;
		printf("Parent is: x=%i\n", x);
}
    return 0;
}
