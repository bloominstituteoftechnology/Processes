// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0){
        printf("Child process %u Child's parent process %u\n",getpid(),getppid());
        execl("/bin/pwd", "pwd", NULL);
    } else {
        wait(NULL);
        printf("The parent is running at %u\n",getpid());
        execl("/bin/ls", "ls", NULL);    
    }
    return 0;
}
