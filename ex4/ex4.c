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
//    printf("Parent %d\n", (int) getpid());
    
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    } else if (rc == 0) {
//        printf("Child process here\n");
//        char *args[] = {"ls", "-l", NULL};
//        execvp(args[0], args);
        
//        execl("/bin/ls", "ls", "-l", (char *) NULL);
        
//        execv("/bin/ls", args);
        
        execlp("ls", "ls", "-l", (char *) NULL);
        
    } else {
        wait(NULL);
    }    

    return 0;
}
