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

    if(rc < 0 ) {
        //do nothing
        exit(1);
    } else if (rc == 0) {
        // this is the child process
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("p3.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        //execcl(); // ask to explain int execl(const char *path, const char *arg, ...);
        //execcle(); // ask to explain int execle(const char *path, const char *arg,
                   //..., char * const envp[]);
    } else {
        // this is the parent process

    }
    return 0;
}
