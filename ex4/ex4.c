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

    int rc = fork();

    if (rc < 0) {
        printf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello from child\n");
        char *args[3];
        args[0] = strdup("/bin/ls"); /* /bin/ls --> command you use to list the contents of a directory
        Expected output: ex4.c since that is what ex4 directory contains*/
        args[1] = strdup("ex4.c");
        args[2] = NULL;
        execvp(args[0], args); // output:   ex4.c
        // execv(args[0], args); // output:  ex4.c
        // execl(args[0], args); // output:   ex4     ex4.c
        // execle(args[0], args); // output:  ex4     ex4.c
        printf("this should not be seen"); /* this statement is never seen bc "/bin/ls" becomes
        the child process's code and this printf no longer exists.*/
    } else {
        int wc = waitpid(rc, NULL, 0); 
        printf("goodbye from parent\n");
    }

    return 0;
}