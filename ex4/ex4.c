// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// exec l versions accept fixed number of stuff, so if you know how many arguments there will be in advance they will automatically be put in an array.
// exec v versions accept an array, so if you don't know how many arguments there will be use this one
// adding p gives the path of the calling file so then you don't need to use /bin/ls for example and can just use ls, since it is #included in the calling file
// adding e specifies the environment/variables of the executing file via passing an array of pointers to char strings

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("hello, child here (pid: %d) \n", (int)getpid());
        char *myargs[3];
        // myargs[0] = strdup("/bin/ls");
        // when using p (execlp execvp etc) you pass in the environment path so that you don't need to put it in myargs[0], so you can use the commented line below
        myargs[0] = strdup("ls");
        myargs[1] = strdup("ex4.c");
        myargs[2] = NULL;
        // execv(myargs[0], myargs);
        execvp(myargs[0], myargs);
        // execl(*myargs, NULL);
        // execlp(*myargs, NULL);
        // execle(*myargs, NULL);
        printf("this should not be seen");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    }

    return 0;
}
