// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>// added to use strdup()
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here
    //fork initialized
    int rc = fork();

    //fork failed, then exit here w message w standard error output.
    if (rc < 0)
    {
        fprintf(stderr, "fork has failed\n");
        exit(1);
    }
    //child process using execvp to print out ex4  ex4.c
    else if (rc == 0)
    {
        printf("CHILD process print check \n");
        char *c_args[4];
        c_args[0] = strdup("/bin/ls");// works and prints out standard output ex4  ex4.c
        c_args[1] = NULL;
        c_args[2] = NULL;
        c_args[3] = NULL;
        execvp(c_args[0], c_args);
    }

    else
     {
         wait(NULL);
    }

    return 0;
}
