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
    // char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 }; used with execle
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child process, pid(%d)\n", (int) getpid());
        // execl("/bin/ls", "ls", "-l", 0);
        char *args[]={"/bin/ls", "-a", "/Users/amyshackles/LambdaSchool/CS10", NULL };
        execvp(args[0], args);
        printf("I've made a terrible mistake\n");
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("Waiting for the child process\n");
        
    }
    return 0;
}
