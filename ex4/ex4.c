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
    int test = fork();

    int test2;
    char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
    //char *cmd[] = { "ls", "-l", (char *)0 };
    
    //test2 = execl ("/bin/ls", "ls", "-1", (char *)0);

    test2 = execle ("/bin/ls", "ls", "-1", (char *)0, env);
    
    

    //test2 = execv("/bin/ls", cmd);
    // Your code here    

    return 0;
}
