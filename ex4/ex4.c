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
    int child = fork();

    if (child == 0){
        printf("PWD includes:\n");

        execl("/bin/ls","ls",NULL);
    }
    else{
                int wc = wait( NULL);

        printf("Parent signing off\n");
    }
    return 0;
}
