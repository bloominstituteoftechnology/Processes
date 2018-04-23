// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// Interesting the varaible retains the value the it was assigned within its scope. So since it was assigned 100 in the parent
// it retained that value within parent scope even after the child reassigned it to 1.
// This is a good visialization of the effects of cloning. 2 instances of the code with seperate memory.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
	int x = 100;

	printf("Pre Fork // In Parent // x = %d.\n", x );
	int rc = fork();

	if(rc < 0) {
		printf("You fool, you have failed to fork...bad child.\n");
		exit(1);
	} else if (rc == 0) {
		x = 1;
		printf("Post Fork // In child // x = %d.\n", x);
	} else {
		printf("Post Fork // In Parent // x = %d.\n", x);
	}

    return 0;
}
