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
    int forked = fork();

    if(forked < 0){
        fprintf(stderr, "Fork attempt failed.\n");
        exit(1);
    } else if (forked == 0){
        char *user_program[2];
        user_program[0] = "/bin/ls";
        user_program[1] = NULL;
        execvp(user_program[0], user_program);
    } else {
        wait(NULL);
        printf("Child process is complete.\n");
    }

    return 0;
}
