// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here    
    int new_fork = fork();
    if (new_fork < 0) {
        printf("Forkage Failure!");
        exit(1);
    } else if (new_fork == 0) {
        printf("Child fork starting up");
        char *myargs[3];
        myargs[0] = "/bin/ls";
        if (argv[1]) {
            myargs[1] = argv[1];
        } else {
            myargs[1] = ".";
        }
        myargs[2] = NULL;
        /* execvp("/bin/ls", myargs); */
        execl(myargs[0], myargs[0], myargs[1], myargs[2]);
    } else {
        waitpid(new_fork, NULL, 0);
        printf("Parent process running now\n");
    }

    return 0;
}
