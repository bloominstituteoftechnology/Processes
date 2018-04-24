// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    // clone parent process to a child
    int rc = fork();

    if(rc == 0){
        // in child process
        //initialize a pointer to array of 3
    	char *myargs[3];
        //assign values to array index
    	myargs[0] = strdup("ls");
    	myargs[1] = strdup("ex4.c");
    	myargs[2] = NULL;
        // execute the file (string)
    	execvp(myargs[0], myargs);
    }   

    return 0;
}
