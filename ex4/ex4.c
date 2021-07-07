// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// referenced: https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/fork_exec/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child Process\n");

        char *myargs[3];
        myargs[0] = "ls";
        myargs[1] = "-1";
        myargs[2] = NULL;

        execv("/bin/ls", myargs);
        printf("If you're reading this, something went wrong\n");
    } else {
		sleep(1);
        execl("/bin/ls", "ls", "-1", NULL);
        printf("If you're reading this, something went wrong\n");
    }

    return 0;
}
