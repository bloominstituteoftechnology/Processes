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
    printf("Initial Process (pid: %d)\n", (int) getpid());

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if(rc == 0)
    {
        printf("Child Process (pid: %d)\n", (int) getpid());
        // int execl(const char *path, const char *arg, ...);
        // With execl(), you have to list the arguments one by one; 
        // it is only useful if you know exactly what you're going to execute ahead of time:
        // If you don't know how many arguments you'll have to deal with, use execvp() or one of the other members of the execv*() family.
        // With the execl*() functions, you specify the program to be run as the first argument, and this is then followed by the argument vector written out:
        execl("/bin/ls", "ls", "-l", (char *)0);
        perror("execl() failure!\n");   

        printf("This print is after execl() and if you see it, it means FAIL!\n");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent Process (pid: %d)\n", (int) getpid());
    }    

    return 0;
}
