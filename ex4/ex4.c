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
    int returnVal;
    char *myargs[3];
    int rc = fork();

    if(rc < 0){
        printf("fork failed\n");
        exit(1);
    }else if (rc == 0){
        returnVal = execl("/bin/ls", "ls", (char*)0);
        printf("Executable return value in child: %d\n", returnVal);
    }else{
        myargs[0] = "/bin/lc";
        myargs[1] = NULL;
        
        returnVal = execvp(myargs[0], myargs);
        printf("Executable return value in parent: %d\n", returnVal);
        
    }

    return 0;
}
