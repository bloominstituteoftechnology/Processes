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
    int rv = fork();

    if(rv < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rv == 0)
    {
        char *myargs[] = {"/bin/ls",NULL};
        // execl(myargs[0], myargs);
        // execle(myargs[0], myargs, char * const envp[] */);
        execv(myargs[0], myargs);
    }
    else
    {
        int wc = waitpid(rv, NULL, 0);
    } 

    return 0;
}
