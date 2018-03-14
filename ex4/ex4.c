// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here    
    //int f = fork();
    // execl: takes args as parameters
    //execl("/bin/ls", "ls", "-l", (char *) 0);
    // execle: 
    //execle("/bin/ls", "ls", "-l", (char *) 0);
    // execv: takes args as an array
    char *args[] = {"ls", "-1", (char *) 0};
    execv("/bin/ls", args);
    return 0;
}
