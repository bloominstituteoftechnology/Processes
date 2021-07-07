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
    char *myargs[] = {"/bin/ls",NULL};
    // char *const envp[] = {NULL};

    if(rv < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rv == 0)
    {
        int rc = fork();

        if(rc < 0)
        {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc == 0)
        {
            printf("Child#2, pid: %d\n", getpid());
            execl(myargs[0], myargs[0], (char *) NULL);
        }
        else
        {
            int wc = waitpid(rv, NULL, 0);
            printf("Child#1 Parent#2, pid: %d\n", getpid());
            execle(myargs[0], myargs[0], (char *) NULL, (char *) NULL);
        }
    }
    else
    {
        int wc = waitpid(rv, NULL, 0);
        printf("Parent#1, pid: %d\n", getpid());
        execv(myargs[0], myargs); 
    } 

    return 0;
}
