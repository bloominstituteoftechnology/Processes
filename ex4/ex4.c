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
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; ercit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        char *args[3];
        args[0] = strdup("/bin/ls");
        args[1] = strdup(".");
        args[2] = NULL;
        // execv(args[0], args);
        execl("/bin/ls", "bin", args[1], args[2]);
        printf("Child process.\n");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("I am the parent.\n");
    }
    return 0;
}
