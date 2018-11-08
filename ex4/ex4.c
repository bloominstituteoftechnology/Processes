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
    pid_t pid = fork();
    char *myargs[] = {"/bin/ls", "-l", 0};

    printf("Hello, process! (pid: %d).\n", (int) getpid());
    if (pid < 0) {
        printf("Forking failed!");
    } else if (pid == 0) {
        printf("Hello from child. (pid: %d)\n", (int) getpid());
        execvp(myargs[0], myargs);
    } else {
        printf("Hello from parent. (pid: %d)\n", (int) getpid());
        execvp(myargs[0], myargs);
    }

    return 0;
}
