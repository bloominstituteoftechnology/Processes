// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child here\n");
        // char *args[] = {"ls", "-l", NULL};
        // execvp("ls", args);
        //above is what sean put
        execl("/bin/ls", "ls", "-l" NULL);
        //p means you do not have to specify path
    } else {
        int wc = wait(NULL);
        printf("parent here\n");
    }

    return 0;
}
