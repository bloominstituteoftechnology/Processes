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
    pid_t pid;
    pid = fork();    
    if (pid < 0) {
        printf("Error %u\n", getpid());
    } else if (pid == 0) {
        printf("Child, pid = %u\n", getpid());
        char *args[] = {"/bin/ls", NULL};
        execv(args[0], args);
    } else {
        printf("Parent, pid = %u\n", getpid());
    }

    return 0;
}
