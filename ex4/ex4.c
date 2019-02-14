// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here    
    int rc = fork();
    if(rc < 0 ){
        printf("Process broke");
    } else if (rc == 0){
        char *cmds[2];
        cmds[0] = strdup("/bin/ls");
        cmds[1] = NULL;
        execv(cmds[0], cmds);
    } else {
        printf("This is the parent");
    }

    return 0;
}
