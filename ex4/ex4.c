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
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am the child.\n");
    } else {
        waitpid(rc, NULL, 0); // wait for child
        printf("I am the parent.\n");
    }

    char* args[] = { "", NULL };
    execvp("/bin/ls", args);

    return 0;
}
