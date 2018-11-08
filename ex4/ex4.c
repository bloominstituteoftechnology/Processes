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
    int spoon = fork();
    
    if (spoon < 0) { 
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (spoon == 0) { 
        printf("this is the child(pid: %d)\n", (int) getpid());
        char *argv[2];
        argv[0] = "/bin/ls";
        argv[1] = NULL;
        execv(argv[0], argv);
        printf("print\n");
     } else {
        wait(NULL);
        printf("exec complete\n");
     }

    return 0;
}
