// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ERROR_FORK[] = "System failed to execute fork()!";

int main(int argc, char *argv[])
{
    // Your code here
    printf("Hello from parent..\n");
    int x = 100;
    int y;
    int f = fork();

    if (f < 0)
    {
        printf("%s", ERROR_FORK);
    }
    else if (f == 0)
    {
        y = x / 2;
        char *myargs[6];
        myargs[0] = strdup = "wc";
        myargs[1] = printf("x after the half-life is %d\n", y);
        myarg[2] = y /= 2;
        myarg[3] = printf("x after the second half-life is %d\n", y);
        myarg[4] = strdup = "/bin/ls";
        myarg[5] = NULL;
        execvp(myarg[0], myargs);
        printf("This should not be seen..");
    }
    else
    {
        int wc = waitpid(f, NULL, 0);
        printf("Hello from parent again (pid: %d)", (int)getpid(), f);
    }

    return 0;
}
