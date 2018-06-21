// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0 ) {
        puts("something went wrong with the fork!");
        exit(1);
    } else if (rc == 0) {
        char* myArgs[3];

        myArgs[0] = "ls";
        myArgs[1] = NULL;
        execvp(myArgs[0], myArgs);
        puts("should not see this");
    } else {
        waitpid(rc, NULL, 0);
    }

    return 0;
}
