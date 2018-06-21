// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here execvp (pid: %d) \n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = strdup("-l");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this should not be seen");
    } else {
        int wc = waitpid(rc, NULL, 0);
    }
   int c = fork();
    if (c < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (c == 0) {
        printf("hello, child here execv (pid: %d) \n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = strdup("-l");
        myargs[2] = NULL; 
        execv("/bin/ls", myargs); 
        printf("this should not be seen");
    } else {
        int wc = waitpid(c, NULL, 0);
    }
    return 0;
}
