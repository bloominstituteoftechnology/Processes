// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Your code here  
    int rc = fork();
    

    if (rc < 0) {
    	printf("Fork failed...\n");
    } else if (rc == 0) {

    	char *my_args[3];

    	my_args[0] = strdup("/bin/ls");
    	my_args[1] = strdup("ex4.c");
    	my_args[1] = NULL;

    	execvp(my_args[0], my_args);
    }

    return 0;
}
