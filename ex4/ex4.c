// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    int rc = fork();
    if (rc < 0) {
        // fork failed
        exit(1);
    } else if (rc == 0) {
        printf("child here\n\n");
        execl("/bin/ls", NULL);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("parent here\n\n");
        
    }

    return 0;
}
