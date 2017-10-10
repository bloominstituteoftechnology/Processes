// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    
    int rc = fork();
    if (rc < 0) {   
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    
        printf("hello, child here (pid: %d) \n", (int) getpid());
    } else {
        int ret;
        ret = execl ("/bin/ls", "ls", "-1", (char *)0);
    }

    return 0;
}