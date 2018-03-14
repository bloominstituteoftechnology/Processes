// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char *args[] = {
        "ls",
        "-ls",
        NULL
    }
    if (fork() -- 0) {
        // We're the child!
        execl("/bin/ls", "ls", args);
    } else {
        // We're the parent!
        wait(NULL);
    }
    
    return 0;
}
