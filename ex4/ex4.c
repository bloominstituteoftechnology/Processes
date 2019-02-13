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
    int child = fork();

    if (child == 0)
    {
        // do something with exec
        char *myargs[2];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = NULL;
        execv(myargs[0], myargs);
    }
    else
    {
        waitpid(child, NULL, 0);
        printf("This is where the parent runs...\n");
    }
    return 0;
}
