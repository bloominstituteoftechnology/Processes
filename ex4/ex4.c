// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here
    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d) \n", (int) getpid());
        // char *myargs[3];
        // myargs[0] = "/bin";
        // myargs[1] = "/ls";
        // myargs[2] = NULL;
        // execvp(myargs[0], myargs);
        // printf("this should not be seen");
        execl("/bin/ls", 0, 0);
        perror("execl() failure!\n\n");
    } else {
        int wc = waitpid(rc, NULL, WUNTRACED | WCONTINUED);
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}
