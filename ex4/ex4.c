// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here    
    printf("This is the parent process.\n");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Fork unsuccessful.\n");
        exit(1);
    }

    else if (rc == 0)
    {
        printf("This is the child process.\n");

        // The "l" in the execl() system call signifies individual parameters in the call
        // The "v" in the execv() system call signifies an array of characters, when it's not known whether there'll be 
        // more than 1 parameter to be passed into the child process
        execl("/bin/ls", "ls", "-l", (char *) NULL);

        // char *args[] = {"ls", "-1", NULL};
        // execv("/bin/ls", args);

        // execlp("ls", "ls", "-l", (char *) NULL);        

        // char *args[] = {"ls", "-1", NULL};
        // execvp("ls", args);
    }

    else
    {
        wait(NULL);
    }

    return 0;
}
