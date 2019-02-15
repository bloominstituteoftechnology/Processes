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
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // Lecture examples
        // char *args[] = {"ls", "-l", NULL};
        // execvp(args[0], args);
        // execl("/bin/ls", "-ls", "-l", (char *)NULL);

        char *parmList[] = {"/bin/ls", "-1", "./", NULL};
        execv(parmList[0], parmList);
        // execl("/bin/ls", "ls", (char *)NULL);
        printf("should not see \n");
    }
    else
    {
        waitpid(rc, NULL, 0);
    }

    return 0;
}
