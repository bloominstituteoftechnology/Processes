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
    int rc = fork;

    if (rc < 0) 
    {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    }
    else 
    {
        //execl("/bin/ls", "ls", NULL);
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
    }

    return 0;
}
