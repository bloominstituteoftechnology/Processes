// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    
    fp = fopen("text.txt", "r");

    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("\nhello, child here (pid: %d) \n", (int) getpid());
        fp = fopen("text.txt", "w+");
        printf("this is the file descriptor in the child scope: %p\n", fp);
        
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("this is the file descriptor in the parent scope: %p\n", fp);
    }

    return 0;
}
