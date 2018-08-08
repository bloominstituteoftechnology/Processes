// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "w");
    // fprintf(fp, "%s", "this is a test\n");
    // fprintf(fp, "%s", "this is a test2\n");
    int rc = fork();
    
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d)\n", (int) getpid());
        fprintf(fp, "%s", "this is a test in child\n");
        
    } else {
        printf("Hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        fprintf(fp, "%s", "this is a test in parent\n");
        
    }
    fclose(fp);
    
    return 0;
}
