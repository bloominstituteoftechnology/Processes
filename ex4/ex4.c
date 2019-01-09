// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    printf("Hello world (pid %d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {
        printf("Why did the fork stop hanging around with the spoon?\n");
        printf("Because the spoon kept stirring up trouble");
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {        
        char *args[3];
        args[0] = "ls";
        args[1] = "-t";
        args[2] = NULL;

        execvp(args[0], args);
        printf("I'm hiding!");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("I am the parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }
    return 0;
}


/*
    myArgs:
        1. file we want to run
        2. argument here
        3. NULL

    execl(), execlp(), and execle():
        - think of (arg0, arg1, arg2..... arg(n))
        - LAST arg must be NULL Pointer (arg[99] = NULL)

    execv(), execvp(), and execvpe():
        - "provides an array of pointers to NULL-terminated characters" 
        - LAST arg must be NULL Pointer (arg[99] = NULL)
        - Seem to be a set number of args for this (as they are provided in definition)

    execle() and execvpe():
        - Allows caller to specify env of executed program (using the arg `envp`)
            - envp == array of pointers to null-term. strings
            - MUST BE TERMINATED BY NULL POINTER 

*/