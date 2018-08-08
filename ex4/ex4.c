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
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("this should be seen\n");
        char *execArgs[3];  
        execArgs[0] = strdup("/bin/ls");  
        execArgs[1] = NULL;        
        execvp(execArgs[0], execArgs);
        printf("this should not be seen\n");
    } else {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
    }

    return 0;
}
