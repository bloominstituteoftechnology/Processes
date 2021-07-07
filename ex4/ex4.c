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
    int fourth = fork();
    if(fourth < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(fourth == 0) {
        printf("Hello, child here. (pid: %d) \n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("ex4.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }
    else {
        waitpid(fourth, NULL, 0);
        printf("Hello, parent here. (pid: %d) \n", (int) getpid());
    }
    return 0;
}
