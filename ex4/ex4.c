// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    printf("Parent process here \n");

    int childProcess = fork();
    if (childProcess < 0) {
        fprintf(stderr, "Error: Could not fork!");
        exit(1);
    } else if (childProcess == 0) {
        char *myargs[3];
        myargs[0] = strdup("ws");
        myargs[1] = strdup("/bin/ls");
        execv(myargs[0], myargs);
    } else {
        int wc = waitpid(childProcess, NULL);    // `waitpid` call added here
         printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), childProcess);
    }

    return 0;
}
