// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *args[] = {};

    if (fork() ==0) {
        execl("/bin/ls", "ls", "~la", NULL);
    } else {
        printf("I'm about to run ls\n");
    }


    return 0;
}
