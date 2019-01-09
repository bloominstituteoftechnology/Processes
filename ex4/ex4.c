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
    char *args[3];
    args[0] = "ls";
    args[1] = "../";
    args[2] = NULL;
    char *weird[2];
    weird[0] = "";
    weird[1] = NULL;
    if(rc==0)
    {
        printf("Child\n");
        execl("/bin/ls" ,args[0], args[1], args[2]);
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("Parent\n");
        execvp(weird[0], weird);
    }

    return 0;
}
