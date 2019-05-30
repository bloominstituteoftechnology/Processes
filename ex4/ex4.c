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
    int returnValue = fork();

    if (returnValue == 0)
    {
        char *my_args[2];
        my_args[0] = "/bin/ls";
        my_args[1] = NULL;
        execvp(my_args[0], my_args);
        printf("Child process\n");
    }
    else
    {
        int wc = waitpid(returnValue, NULL, 0);
        printf("Parent process\n");
    }
    return 0;
}
