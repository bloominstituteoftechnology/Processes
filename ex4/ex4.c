// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here    
    pid_t pid;
    pid = fork();

    if (pid < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {    // child process satisfies this branch
        execl("/bin/ls","ls", NULL);
        printf("hello\n");
    } else {
        int wc = waitpid(pid, NULL, 0);    // `waitpid` 
        printf("goodbye\n");
    }

    return 0;
}
