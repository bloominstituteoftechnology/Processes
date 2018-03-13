// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    int child = fork();

    if (child < 0)
    {
        printf("Unable to fork\n");
        exit(1);
    }
    else if (child == 0)
    {
        printf("Child fork\n");
        execl("/bin/ls", "ls", "-la", NULL);
        printf("Child completed\n");
    }
    else
    {
        int wait = waitpid(child, NULL, 0);
        printf("Parent\n");
    }

    return 0;
}
