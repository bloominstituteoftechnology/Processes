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
    // Your code here
    int child = fork();

    if (child < 0) {
        perror("fork failed\n");
        exit(1);
    }
    else if (child == 0) {
        int child2  = fork();

        if (child2 < 0) {
            perror("second fork failed\n");
            exit(1);
        }
        else if (child == 0) {
            char *args[2];
            args[0] = strdup("ls");
            args[1] = NULL;
            execvp(args[0], args);
            printf("shouldnt get here 2");
        }
        printf("\n\n");
        int wc = waitpid(child2, NULL, 0);
        execlp("/bin/ls", "ls", NULL);
        printf("shouldnt get here");
    }
    else {
        int wc2 = waitpid(child, NULL, 0);
        printf("End");
    }
    return 0;
}
