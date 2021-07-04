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
    int pid = fork();
    
    if (pid == 0){
        char *args[] = {"/bin/ls", NULL};
        printf("This is child running /bin/ls.\n");
        execvp("/bin/ls",args);
    } else {
        wait(NULL);
        printf("This is parent running /bin/ls.\n");
        char *args[] = {"/bin/ls", NULL};
        execvp("/bin/ls",args);
    }
    return 0;
}