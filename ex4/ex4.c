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
    if (rc < 0) {
        fprintf(stderr, "fork has failed\n");
        exit(1);
    }   else if (rc == 0) {
        printf("Child (pid: %d)\n", (int) getpid());
        char *argarray[3];
        argarray[0] = strdup("ls");
        argarray[1] = strdup("-l");
        argarray[2] = NULL;
        execvp(argarray[0], argarray);
        printf("If this message is read, there is something wrong with the child process");
    }   else {
        int wc = waitpid(rc, NULL, 0);
        printf("parent(pid: %d), child of parent %d\n", (int) getpid(), rc);
    }


    return 0;
}
