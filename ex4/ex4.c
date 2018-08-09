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
    int child = fork();

    if (child < 0)
    {
        printf("Error creating child process");
        exit(1);
    }
    else if (child == 0)
    {
        char *my_args[3];
        my_args[0] = "/bin/ls";  // this is analogous to using `ls` in the terminal
        my_args[1] = "-la";  // the same as using the `-la` flag with `ls`, e.g. `ls -la`
        my_args[2] = NULL;  // calls to any `exec` function requires our char pointer array to be terminated with a `NULL`
        
        execv("/bin/ls", my_args);
    }
    else
    {
        waitpid(child, NULL, 0);
        printf("\nParent Complete\n\n");
    }

    return 0;
}
