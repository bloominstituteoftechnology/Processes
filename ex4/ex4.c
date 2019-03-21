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
    pid_t pid = fork();
    
    if (pid == 0) {
        // execlp("ls", "ls", NULL);
        char *cmd = "ls";
        char *argv[3];
        argv[0] = "ls";
        argv[1] = "-la";
        argv[2] = NULL;

        execvp(cmd, argv); //This will run "ls -la" as if it were a command
    } else {
        wait(NULL);
        printf("Child process has ended\n");
    }
    return 0;
}
