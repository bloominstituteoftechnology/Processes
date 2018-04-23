// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int child = fork();
    
    if (child < 0) {    
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (child == 0) {    
        char *myargs[2];    
        myargs[0] = strdup("dir");      
        myargs[1] = NULL;       
        execvp(myargs[0], myargs);     
        printf("This should not be seen\n");
    } else {
        int wc = waitpid(child, NULL, 0);  
        printf("Parent: That should be the directory above\n");
    }

    return 0;
}
