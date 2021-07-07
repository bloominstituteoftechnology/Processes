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
    printf("Parent process here\n");
    // system call to create new child process
    int rc = fork();

    // checking for if its less than
    if (rc < 0) {
        // printing error results
        fprintf(stderr, "fork failed\n");
        // exit status of failure
        exit(1);
    }
    // checking for equal to
    else if (rc == 0)
    {
        printf("Child process here\n");
        // creating a pointer
        char *args[] = {"ls", "-l", NULL};
        // arrays of pointers to null-terminated strings that represent the argument list available to the new program. 
        // first argument points to the filename being executed
        execvp("ls", args);
    }
     else 
     {
        //  wait for process to end function
        int wc = waitpid(rc, NULL, 0);
    }
    // program completion
    return 0;
}
