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
    int rc = fork();   
    char *myargs[1];
    myargs[0] = "/bin/ls";
    myargs[1] = NULL;

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if ( rc == 0 ){
        printf("Accessing child...\n");
        execv(myargs[0], myargs);
        printf("test run failed\n");
    } else {
        wait(NULL);
        printf("Accessing parent...\n");
    }

    return 0;
}
