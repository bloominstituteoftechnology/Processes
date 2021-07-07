// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x =100;
    pid_t pid;
	
    pid=fork();
	
    if(pid<0){
    	fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(pid==0){
	x=80;    
    	printf("I'm the child! and x = %d\n", x);  //child changes the value of x and prints it out
    }
    else{
	x=99;    
    	printf("I'm the parent! and x = %d\n", x); //parent changes the value of x and prints it out
    }
     

    return 0;
}
