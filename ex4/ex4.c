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
    int pid = fork();
    if(pid == 0){
    execl("/bin/ls", "execl in child"  ,NULL);
    } else {
        execl("/bin/ls", "execl in parent"  ,NULL);
    }

    return 0;
}
