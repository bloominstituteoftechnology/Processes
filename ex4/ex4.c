// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d) \n", (int) getpid());
        printf("hello\n");
        char *myargs[3];
        myargs[0] = strdup("wc");      // pass the name of the program we want to run as the first array element
        myargs[1] = strdup("text.txt");    // argument: the file to count
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("goodbye\n");
    }
    
    return 0;
}
