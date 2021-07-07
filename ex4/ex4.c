// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// -> Because theyare different in the way they pass arguments to the called process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork(); 
    if (rc < 0){
        printf("fork failed");
    }else if(rc == 0){
        execl("../ex3/ex3", "ls", "l", (const char*) NULL);
    }

    return 0;
}
