// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    int rc = fork();

    if (rc == 0)
    {
        //Child Here
        printf("From the Child\n");
        execl("/bin/ls", "ls", NULL);
        printf("From the Child after execl\n"); // This line gets ignored because execl overwrites the process
    }
    else
    {
        wait(NULL);
        //Parent Here
        printf("From the Parent\n");
        execl("/bin/ls", "ls", NULL);
        printf("From the Parent after execl\n"); // This line gets ignored because execl overwrites the process
    }

    return 0;
}
