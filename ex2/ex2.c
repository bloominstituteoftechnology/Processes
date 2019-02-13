// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int c;
    FILE *file;
    
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
        file = fopen("text.txt", "w");
        fprintf(file, "Child was here");
        fclose(file);
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        file = fopen("text.txt", "w");
        fprintf(file, "Parent was here");
        fclose(file);
    }
    
    file = fopen("text.txt", "r");
    
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
        printf("\n");
    }
    
    return 0;
}
