// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here    
    const char *ls = "/bin/ls";
    int rc = fork();
    
    if (rc == 0) {
        printf("i am the child and now im going to call LS\n");
        execv(ls, NULL);
        return 0;
    } else if (rc != 0) {
        waitpid(rc, NULL, 0);
        printf("the child has called LS\n");
        return 0;
    }

    return 0;
}
