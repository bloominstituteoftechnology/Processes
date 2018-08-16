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
    // create the child process
    int rc = fork();

    if (rc < 0)
    {
        // send a standard error for if the fork fails
        fprintf(stderr, "fork failed\n");
        // break
        exit(1);
    }
    else if (rc == 0)
    {
        // let the user know about the child process
        printf("Child process here\n");

        // /*Commented out below are 3 alrtnate exec() methods*/

        // execl("/bin/ls", "ls", "-l" (char *) NULL);
        
        // char *args[] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);

        //execlp("ls", "ls", "-l", (char *) NULL);

        // transform the child process into ls
        char *args[] = {"ls", "-l", NULL};
        // call exec()
        execvp("ls", args);
        // proof the code doesn't reach this line
        printf("This should not be seen\n");
    }
    else
    {
        // have the parent wait, then print
        int wc = waitpid(rc, NULL, 0);
        printf("Parent process here\n");
    }

    return 0;
}
