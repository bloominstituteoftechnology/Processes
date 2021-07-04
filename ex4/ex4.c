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
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("../");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("This should not run");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf(" ^List of the Project files^\n");
    }
    return 0;
}
