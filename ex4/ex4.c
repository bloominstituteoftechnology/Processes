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
    int temp = fork();
    if(temp == 0){
        char *args[2];
        args[0] = "bin/ls";
        args[1] = NULL;
        execvp(args[0], args);
        printf("Child process\n");

    }else if(temp < 0){
        printf("fork failed\n");
    }
    else
    {
        int wc = waitpid(temp, NULL, 0);
        printf("Completed child process\n");
    }
    return 0;
}
