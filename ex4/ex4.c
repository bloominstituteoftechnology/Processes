// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    int forked=fork();
    if (forked==0){
        char *myprograms[1];
        myprograms[0]="/bin/ls";
        execvp(myprograms[0],myprograms);
    } else {
        wait(0);
        printf("Child is done running.");
    }
    return 0;
}
