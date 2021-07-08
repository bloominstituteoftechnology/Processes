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
    printf("Parent process.... %d", (int)getpid()); 
    char *args[] = {"ls", "-m", NULL}; 
    int s = fork();

    if(s > 0) {
        printf("Parent process.... %d", (int)getpid());
        waitpid(s, NULL, 0);

    } else if(s == 0) {
        printf("child process.... %d", s);
        execvp(args[0], args);
    } 

    return 0;
}
