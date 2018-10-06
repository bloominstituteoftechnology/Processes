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
    int f = fork();
    if (f < 0){
        printf("Fork failed!");
        exit(1);
    } else if(f == 0){
        printf("Child fork");
        char *args[] = {"ls", "-1", NULL};
        execvp("ls", args);
        printf("You really shouldn't see this...");
    } else {
        wait(NULL);
        printf("Parent fork");
    }
    return 0;
}
