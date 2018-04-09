// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork() failed\n");
    }
    else if (rc == 0)
    {
        /* execl() */
        // printf("child:\n");
        // execl("/bin/ls", "/bin/ls", "-l", NULL);
        // printf("this should not print\n");

        /* execle() */
        // char *const envp[4] = {
        //     "/bin/ls",
        //     "ls",
        //     "-l",
        //     NULL};
        // char *args[4];

        // args[0] = "/bin/ls";
        // args[1] = "ls";
        // args[2] = "-l";
        // args[3] = NULL;

        // printf("child:\n");
        // execle(envp[0], envp[1], envp[2], envp[3], envp);
        // printf("this should not print\n");

        /* execv() */
        char *args[3];

        args[0] = "/bin/ls";
        args[1] = "-l";
        args[2] = NULL;

        printf("child:\n");
        execv(args[0], args);
        printf("this should not print\n");

        /*
            all execs print expected output:

            $ ./ex4
            child:
            total 40
            -rw-r--r--  1 *********  staff    48 Apr  9 11:50 Makefile
            -rwxr-xr-x  1 *********  staff  8792 Apr  9 12:33 ex4
            -rw-r--r--  1 *********  staff  1621 Apr  9 12:33 ex4.c
            parent:
            goodbye
        */
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("parent:\n");
        printf("goodbye\n");
    }
    return 0;
}
