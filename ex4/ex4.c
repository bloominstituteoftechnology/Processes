// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// There are so many variants as each is a specialized tool to fit a specific need

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) {
        exit(1);
    } else if (rc == 0) {
        // execl("/bin/ls", "ls", NULL);

        char *args[2];
        args[0] = strdup("/bin/ls");
        args[1] = NULL;
        // execv(args[0], args);
        execvp(args[0], args);
    } else {
        int wc = waitpid(rc, NULL, 0);
    };


    return 0;
}
