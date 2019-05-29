// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?
// Because of different use cases; it's for the sake of having more specifications available.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    fork();

    char *args[] = {"/bin/ls", NULL};
    execvp(args[0], args);
    // execv(args[0], args);


    return 0;
}
