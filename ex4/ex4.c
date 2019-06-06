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
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed.");
        exit(1);
    } else if (rc == 0) {
        char *myArgs[2];
        myArgs[0] = "/bin/ls";
        myArgs[1] = NULL;
        execv(myArgs[0], myArgs);
    } else {
        wait(NULL);
        printf("In parent.");
    }
    return 0;
}
