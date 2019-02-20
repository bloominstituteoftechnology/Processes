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
    int new_process = fork();

    // Return value of fork()
    // On success, the PID of the child process is returned in the parent, and 0 is returned in the child. 

    if (new_process){
        // printf("hello from child\n");
        execl("/bin/ls", "ls", NULL);
    } else {
        // printf("goodbye from main\n");
    }   

    return 0;
}
