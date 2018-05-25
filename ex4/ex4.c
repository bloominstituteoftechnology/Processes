// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fk = fork();

    if (fk < 0)
    {
        printf(stderr, "OMGFE!!!");
        exit(1);
    }
    else if (fk == 0)
    {
        printf("Stop, change everything\n");
        // exec()
        char *myArgs[3];
        myArgs[0] = strdup("/bin/ls");
        myArgs[1] = NULL;
        myArgs[2] = NULL;
        execl(myArgs[0], myArgs);
        printf("Will not be seen\n");
    }
    else
    {
        printf("You are in the parent, perv\n");
    }

    return 0;
}
