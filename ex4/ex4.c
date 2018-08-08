// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h> // using printf() from library
#include <unistd.h> // let's us run exec()
#include <stdlib.h> // let's us run fork()
#include <sys/wait.h> // let's us run wait()

int main(void)
{
    int forked = fork();

    if (forked < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (forked == 0) { //this is the child process
        char *args[]={"/bin/ls","-a", "--color", NULL};
        execvp(args[0],args);
    }
    else {
        char *args[]={"/bin/ls","-lA", "--color", NULL};
        execv(args[0],args);
    }

    return 0;
}
