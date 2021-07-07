// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

/*
> Why do you think there are so many variants of the same basic call?


*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Have you tried using spoons? Stop with the forks already!\n");
        exit(1);
    } 
    else if (rc == 0) {
        char *myargs[2];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
        printf("didn't work, bruh\n");
    } 
    else {
        printf("ol' parent process hanging around, yuh\n");
    }
    return 0;
}
