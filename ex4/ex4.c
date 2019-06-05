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

    printf("starting program\n");
    printf("%s", "hello");
    exec("/bin/ls", "ls", NULL);
    printf("ran ls\n");

    execlp("/bin/ls", "ls", NULL);
    pid_t  pid = fork();
    if (pid == 0) // child process
    {
        execle("/bin/cd ex4", "cd", NULL);
        execle("/bin/ls", "ls", NULL);
        // exec("/bin/ls");
    }
    else         // parent process
    {
        execle("/bin/ls", "ls", NULL);

    }
    return 0;
}
