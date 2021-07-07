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
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *args[] = {"./ex3/ex3", NULL};
        execvp(args[0], args);
        printf("this should not be seen");
    } else {
        int wc = waitpid(rc, NULL, 0);
        char *args[] = {"./ex1/ex1", NULL};
        execl(args[0], args[1]);
        printf("this will also not be seen");
    }
    return 0;
}
