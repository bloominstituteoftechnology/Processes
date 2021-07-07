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
    int p[2];
    int rc;
    char buf[4096];

    if (pipe(p) < 0)
    {
        exit(1);
    }

    if ((rc = fork()) < 0) 
    {
        exit(1);
    }
    
    if (rc == 0)
    {
        dup2(p[1], STDOUT_FILENO);
        close(p[0]);
        close(p[1]);
        execl("/bin/ls", "ls");
        exit(0);
    }
    else
    {
        waitpid(rc, NULL, 0);
        close(p[1]);
        read(p[0], buf, sizeof(buf));
        printf("Output:\n%s\n", buf);
    }
    return 0;
}
