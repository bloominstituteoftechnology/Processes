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
    int rc = fork();

    if(rc == 0){
    	char *myargs[3];
    	myargs[0] = strdup("ls");
    	myargs[1] = strdup("ex4.c");
    	myargs[2] = NULL;
    	execvp(myargs[0], myargs);
    }   

    return 0;
}
