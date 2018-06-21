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
    if (rc < 0) {
        exit(1);
    } else if () {
        execvp(argv[1], argv);
    } else {
        int wc = waitpid(rc,NULL,0);
        printf("End of parent process\n");
    }
    return 0;
}

