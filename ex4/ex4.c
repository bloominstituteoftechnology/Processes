// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>  
int main(int argc, char* argv[])
{
    // Your code here    
    char *myargz[]={"/bin/ls", NULL};
    int rc = fork();

    if (rc < 0)
        printf("shits fucked!");
    else if (rc == 0){
        execvp(myargz[0], myargz);

    }
    else{
        int wc = waitpid(rc, NULL, 0);    
        printf("%s\n", "Goodbye");
    }
    return 0;
}
