// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("HeLlO wOrLd =D (pid:%d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "No Fork for YOU!\n");
        exit(1);
    }

    else if (rc == 0) {
        int rc2 = fork();

        if (rc2 < 0) {
            fprintf(stderr, "Second Fork Fail\n");
            exit(1);

    } else if (rc == 0) {
        printf("I am CHILD -_- (pid: %d)\n", (int) getpid());
        char *myargs[3];

        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("-1");
        myargs[2] = NULL;

        execvp(myargs[0], myargs);
        printf("If you're reading this...you know");
    }  
    printf("\n\n");
    int wc = waitpid(rc, NULL, 0);
    execlp("/bin/ls", "ls", NULL);
    printf("Shouldn't be reading this either!");
    } else {
        int wc2 = waitpid(rc, NULL, 0);
        printf("I am PARENT ^_^ (pid: %d) of CHILD %d\n", (int) getpid(), rc);
    }

    return 0;
}
