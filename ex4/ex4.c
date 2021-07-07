// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?
    // They give you different options; such as including arguments as a null terminated array or listing them right in the exec function call, and also determining the environment to execute the desired program.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    /*
    char *args[2];
    args[0] = "/bin/ls";
    args[1] = NULL;

    execv( args[0], args );
    */

    execl("/bin/ls", "ls", NULL);

    return 0;
}
