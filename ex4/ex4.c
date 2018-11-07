// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here
    int f = fork();

    if (f < 0) {
        fprintf(stderr, "Forking failed.\n");
        exit(1);
    } else if (f == 0) {
        printf("Hello!!!! Hobbit is here with a tag of (pid: %d)\n", (int) getpid());
        char *choices[3];
        choices[0] = strdup("/bin/ls");
        choices[1] = strdup("-l");
        choices[2] = NULL;
        execvp(choices[0], choices);
        printf("\nSomething went really wrong and now the computer is gonna blow up :/\n");
    } else {
        waitpid(f, NULL, 0);
        printf("\nBig daddy here (pid: %d) of that Hobbit (pid: %d)\n", (int) getpid(), f);
    }

    return 0;
}
