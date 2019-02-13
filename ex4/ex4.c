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

    int rc = fork(); // rc: return code

    // ------------------------------------------------ child process starts executing here
     if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");//prints to standard error 
        exit(1);

    } else if (rc == 0) {    // child process satisfies this branch
      
        printf("hello, child here (pid: %d) \n", (int) getpid());

    } else {
     
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    
    return 0;
}

