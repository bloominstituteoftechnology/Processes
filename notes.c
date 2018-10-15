// p1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ./executable arg1 arg2    => argc = 3; argv = ["executable", "arg1", "arg2"]
// argc - the number of arguments passed to our executable
// argv - actual contents
// int main(void) - we're not going to use argc and argv

int main(int argc, char *argv[])
{
    // getpid() - another system call that gets the pid or the process identifier of this process where this code is executing
    // each process has identifier associated with it that the OS keeps track of in the list of processes

    printf("hello world (pid: %d)\n", (int)getpid());
    int rc = fork(); // fork returns different things based on the context
    // ------------------------------------------------ child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int)getpid());
    }
    else
    {
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    }

    return 0;
}