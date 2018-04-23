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

    int super_fork = fork();

    if (super_fork < 0)
    {
        printf("something bad happened, sire");
        exit(1);
    }  
    else if (super_fork == 0)
    {
        printf("the child is about to do its thing\n");
        char *args[3];

        args[0] = strdup("/bin/ls");
        args[1] = strdup(".");
        args[2] = NULL;

        execvp(args[0], args);
        // execl(".", args[0], 0);
        // execle(".", args[0], 0, 'a');
        // execv(args, args[1]);
    }
    else
    {
        waitpid(super_fork, NULL, 0);
        printf("and the parent arrived late..\n");
    }

    return 0;
}
