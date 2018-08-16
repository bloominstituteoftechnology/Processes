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
    printf("parent process here\n");
    int rc = fork();

    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }  else if (rc == 0){
        printf("Child process here\n");

        //exel("/bin/ls"), "ls", "-l" (char*) NULL);
        // char * args[] = {"ls", "-1", NULL};
        //execv("/bin/ls" args);
        //execlp("ls",
    }  

    return 0;
}
